import Graphics.UI.GLUT
import Graphics.Rendering.OpenGL 
import Data.IORef 

_ballRadius :: GLfloat 
_ballRadius = 0.02

_topFieldBound    = 0.6
_rightFieldBound  = 0.9
_bottomFieldBound = -0.6
_leftFieldBound   = -0.9
_halfPadelWidth  = 0.025
_halfPadelHeight = 0.13
_padelMoveSpeed  = 0.02

_delayTime = 16 -- about 60 frames per second  

_initBallXVeloc = 0.01250
_initBallYVeloc = 0.0225

data Ball = Ball { coords::(GLfloat, GLfloat),
                   velocity::(GLfloat, GLfloat) }

type Padel = (GLfloat, GLfloat, GLfloat)

data GameState = GameState { ball::Ball , 
                             rPadel::Padel , 
                             lPadel::Padel , 
                             score::(Int,Int) }

resetGameState :: (Int, Int)-> GameState 
resetGameState s = GameState { ball   = Ball (0,0) (_initBallXVeloc, _initBallYVeloc) ,
                            rPadel = (_rightFieldBound + _halfPadelWidth, 0, 0) ,
                            lPadel = (_leftFieldBound  - _halfPadelWidth, 0, 0) ,
                            score  = s }


main :: IO ()
main = do
    getArgsAndInitialize 
    createWindow "Pong -- Corbin Charpentier" 
    initialDisplayMode $= [{-WithDepthBuffer-} DoubleBuffered]
    --depthFunc $= Just Less 
    windowSize $= Size 800 800
    gameState <- newIORef (resetGameState (0,0))
    displayCallback $= (drawScene gameState) 
    reshapeCallback $= Just reshape 
    keyboardMouseCallback $= Just ( keyboardInpt gameState)
    addTimerCallback _delayTime (timerCallback gameState)
    mainLoop

keyboardInpt gameState key state _ _ = do 
    keyAction gameState key state     

-- move left paddle up
keyAction gameState (Char 'a') keystate = do --key state is Up or Down 
    g <- get gameState 
    let (x, y, dir) = lPadel g 
    gameState $= g {lPadel = (x, y, pdlDirUp keystate)}
-- move left padel down
keyAction gameState (Char 'z') keystate = do
    g <- get gameState 
    let (x, y, z) = lPadel g
    gameState $= g {lPadel = (x, y, pdlDirDn keystate)}
keyAction gameState (Char 'r') Down = do
    g <-get gameState
    gameState $= ( resetGameState $ score g )
keyAction _ _ _ = return ()

-- sets move up state for paddle 
pdlDirUp Down = _padelMoveSpeed 
pdlDirUp Up   = 0.0  

pdlDirDn Down = -_padelMoveSpeed
pdlDirDn Up   = 0.0


reshape s@(Size w h) = do
    viewport $= (Position 0 0, s)
    matrixMode $= Projection 
    loadIdentity
    postRedisplay Nothing 

drawScene gameState = do
    loadIdentity
    clear [ColorBuffer]
    color $ (Color3 (0.0::GLfloat) 1.0 0)
    drawField 
    g <- get gameState  
    drawPadel $ rPadel g
    drawPadel $ lPadel g
    drawBall $ ball g   
    swapBuffers 

-- Framerate is limited only by hardware. The timer simulates a framerate of 
--  60 fps by update positions very 16mS. 
timerCallback gameState = do 
    g <- get gameState
    let (b, s) = updateBall (ball g)(lPadel g)(rPadel g)(score g)-- also checks for score
    gameState $= g{ball = b,
                   lPadel = updatePadel (lPadel g), 
                   rPadel = updatePadel (padelAI (rPadel g) b),
                   score  = s }
    postRedisplay Nothing 
    addTimerCallback _delayTime (timerCallback gameState)

updateBall :: Ball -> Padel -> Padel -> (Int, Int) -> (Ball, (Int, Int))
updateBall (Ball (x, y) (xv, yv)) (_,ly,_) (_,ry,_) (sl, sr)
    | y + _ballRadius >= _topFieldBound    = (Ball (x+xv, y-yv) (xv, -yv), (sl,sr))
    | y - _ballRadius <= _bottomFieldBound = (Ball (x+xv, y-yv) (xv, -yv), (sl,sr))
    | x + _ballRadius >= _rightFieldBound  = 
        if y > ry+_halfPadelHeight || y < ry-_halfPadelHeight 
            then (Ball (x, y) (0.0, 0.0), (sl+1, sr))
            else (Ball (x-xv, y+yv) (-xv, yv), (sl,sr))
    | x - _ballRadius <= _leftFieldBound   = 
        if y > ly+_halfPadelHeight || y < ly-_halfPadelHeight 
            then (Ball (x, y) (0.0, 0.0), (sl, sr+1))
            else (Ball (x-xv, y+yv) (-xv, yv), (sl,sr))
    | otherwise = (Ball (x+xv, y+yv) (xv, yv), (sl, sr))


_skewFac = 45.0 -- 0.7853981 -- about 45 degrees  
updateBVec :: Ball ->  Padel -> (GLfloat, GLfloat) --returns new velocity 
updateBVec (Ball (x, y) (xv, yv)) (_,py,_) = 
    let theta_o = (y-py)/_halfPadelHeight*_skewFac 
        y = sqrt(magnitd^2/((tan1 theta_o)^2+1))
        in (y*(tan1 theta_o), y)
            where magnitd = sqrt(xv^2 + yv^2)
        
tan1 theta = r2d $ tan $ d2r $ theta
r2d rads = rads*pi/180
d2r degs = degs*180/pi 
     

padelAI :: Padel -> Ball -> Padel
padelAI (px, py, dir) (Ball (x,y)(xv,yv)) 
    | y > py = (px, py, _padelMoveSpeed)
    | y < py = (px, py, -_padelMoveSpeed)
    | otherwise = (px, py, 0.0)
        

updatePadel (x, y, dir) = if y+dir+_halfPadelHeight <= _topFieldBound
                             && y+dir-_halfPadelHeight >= _bottomFieldBound
                                then (x, y + dir, dir)
                                else (x, y, dir)

drawField = do
    drawAs LineLoop [(0.9, 0.6, 0.0), (0.9, -0.6, 0.0), (-0.9, -0.6, 0.0), (-0.9, 0.6, 0.0)] 
    drawAs LineLoop [(0.0, 0.6, 0.0), (0.0, -0.6, 0.0)] 

drawPadel :: Padel -> IO ()
drawPadel p = preservingMatrix $ do
    let (x, y, _) = p
    translate ( Vector3 x y 0.0 )
    drawAs Quads [(_halfPadelWidth, _halfPadelHeight, 0.0), (_halfPadelWidth, -_halfPadelHeight, 0.0) ,
                  (-_halfPadelWidth, -_halfPadelHeight, 0.0), (-_halfPadelWidth, _halfPadelHeight, 0.0)]

drawBall :: Ball -> IO ()
drawBall b = preservingMatrix $ do
    let c = coords b
    translate $ Vector3 (fst c) (snd c) 0.0
    drawCircle _ballRadius

makeVerts :: [(GLfloat, GLfloat, GLfloat)] -> IO ()
makeVerts = mapM_ (\ (x, y, z)->vertex( Vertex3 x y z ))

drawCircle :: GLfloat -> IO ()
drawCircle radius = drawAs TriangleFan (circle radius)

drawAs :: PrimitiveMode -> [(GLfloat, GLfloat, GLfloat)] -> IO ()
drawAs primitive points = renderPrimitive primitive $makeVerts points 

drawPrimitives :: [(GLfloat, GLfloat, GLfloat)] -> PrimitiveMode -> IO ()
drawPrimitives points primitive = do
    drawAs primitive points 

buildCircle :: GLfloat -> GLfloat -> [(GLfloat, GLfloat, GLfloat)]    
buildCircle radius resolution = [let x = 2 * pi * i /resolution
                                 in (radius * (sin (x)), radius * (cos (x)), 0)
                                | i <- [1,2..resolution]]

circle :: GLfloat -> [(GLfloat, GLfloat, GLfloat)]

circle radius = buildCircle radius 50 







































