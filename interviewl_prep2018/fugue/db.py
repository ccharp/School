import sqlite3

DB_FILE = "fugue_game.db"

def init_db():
    # Yes, anyone can claim to be anyone.
    #   If we really wanted to scale this up, we'd have some service dedicated exclusively to authentication.
    # If end_date is null, game is still active. Client can only have one active game at a time
    create_game_table = """ CREATE TABLE IF NOT EXISTS Games (
                                id integer PRIMARY KEY AUTOINCREMENT,
                                target integer NOT NULL,
                                num_questions integer NOT NULL DEFAULT(0),
                                num_guesses integer NOT NULL DEFAULT(0),
                                user_id text NOT NULL,
                                begin_time TIMEPSTAMP DEFAULT(CURRENT_TIMESTAMP),
                                end_time TIMESTAMP 
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
    rows = execute_sql_command(
        "SELECT target FROM Games WHERE user_id='{0}' AND end_time IS NULL".format(user_id)
    )
    if rows:
        return rows[0][0]
    return None

def create_game(user_id, target):
    sql_insert = """ INSERT INTO Games(target, user_id)
                     VALUES (?, ?)
                 """
    _ = execute_sql_command(sql_insert, (target, user_id))

def increment_guess(user_id):
    increment(user_id, "num_guesses")

def increment_question(user_id):
    increment(user_id, "num_questions")

def increment(user_id, column):
    sql_insert = """ UPDATE Games SET {0} = {0} + 1 
                     WHERE user_id=? AND end_time IS NULL
                 """.format(column)
    execute_sql_command(sql_insert, (user_id,))

def execute_sql_command(sql_command, bindings=None):
    conn = create_connection(DB_FILE)
    cursor = conn.cursor()
    if bindings is not None:
        cursor.execute(sql_command, bindings)
    else:
        cursor.execute(sql_command)
    conn.commit()
    return cursor.fetchall() # list of tuples
