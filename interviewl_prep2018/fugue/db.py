import sqlite3

DB_FILE = "fugue_game.db"

def init_db():
    # Yes, anyone can claim to be anyone.
    #   If we really wanted to scale this up, we'd have some service dedicated exclusively to authentication.
    # If end_date is null, game is still active. Client can only have one active game at a time
    create_game_table = """ CREATE TABLE IF NOT EXISTS games (
                                id integer PRIMARY KEY,
                                target integer NOT NULL,
                                num_questions integer NOT NULL DEFAULT(0),
                                num_guesses integer NOT NULL DEFAULT(0),
                                user_name text NOT NULL,
                                begin_date text NOT NULL,
                                end_date text
                            );
                        """
    conn = create_connection(DB_FILE)
    if conn is not None:
        create_table(conn, create_game_table)

def create_connection(db_file):
    try:
        conn = sqlite3.connect(db_file)
        return conn
    except Exception as e:
        print(e)
 
    return None

def create_table(conn, create_table_sql):
    try:
        c = conn.cursor()
        c.execute(create_table_sql)
    except Exception as e:
        print(e)

def get_game(user_id):
    c = create_connection(DB_FILE).cursor()
    c.execute("SELECT target FROM games WHERE user_name='{0}' AND end_time IS NULL".format(user_id))
    rows = c.fetchall()
    print("get_game. Rows: " + str(rows))

def create_game(user_id):
    c = create_connection(DB_FILE).cursor()

def increment_guess(user_id):
    c = create_connection(DB_FILE).cursor()

def increment_question(user_id):
    c = create_connection(DB_FILE).cursor()