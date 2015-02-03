function [EX,X] = randomSamples(n, para, method)

A = ones(n, 1) * para;

if( strcmp(method, 'bern') )
   X = rand(n,1);
   EX = 0;
   for(i = 1:n)
       if( X(i) < para ) 
           X(i) =1;
       else
           X(i) = 0;
       end
   end
elseif( strcmp(method, 'bino') )
    X = random(method, 1, para, 1, n);
else %Gaussian
    X = random(method, 2.0, para, 1.0, n ); 
end
EX = sum(X)/n;