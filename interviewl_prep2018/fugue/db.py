import sqlite3

DB_FILE = "fugue_game.db"

def init_db():
    # Yes, anyone can claim to be anyone.
    #   If we really wanted to scale this up, we'd have some service dedicated exclusively to authentication.
    # If end_date is null, game is still active. Client can only have one active game at a time
    create_game_table = """ CREATE TABLE IF NOT EXISTS games (
                                id integer PRIMARY KEY,
                                num_questions integer,
                                num_guesses integer,
                                user_name text,
                                begin_date text,
                                end_date text,
                            );
                        """
    conn = creat_connection(DB_FILE)
    if conn is not None:
        create_table(conn, )

def create_connection(db_file):
    try:
        conn = sqlite3.connect(db_file)
        return conn
    except Error as e:
        print(e)
 
    return None

def create_table(conn, create_table_sql):
    try:
        c = conn.cursor()
        c.execute(create_table_sql)
    except Error as e:
        print(e)

def authenticate_user
def get_active_game(user_id):

    return None

