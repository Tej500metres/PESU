
CREATE DATABASE social_media2;
\c social_media2

CREATE TABLE USERS (
    id SERIAL PRIMARY KEY NOT NULL,
    first_name VARCHAR(255) NOT NULL,
    last_name VARCHAR(255) NOT NULL,
    email VARCHAR(255), 
    followers INT DEFAULT 0,
    followings INT DEFAULT 0,
    num_posts INT DEFAULT 0, 
    age INT NOT NULL,
    joined_date DATE NOT NULL DEFAULT CURRENT_DATE
);


CREATE TABLE POST (
    id SERIAL PRIMARY KEY NOT NULL,
    author_id INT REFERENCES USERS(id) ON DELETE CASCADE,
    date_posted DATE NOT NULL DEFAULT CURRENT_DATE,
    title VARCHAR(300) NOT NULL,
    content TEXT NOT NULL
);

CREATE TABLE JOBINVITATIONS (
    id SERIAL PRIMARY KEY NOT NULL,
    author_id INT REFERENCES USERS(id) ON DELETE CASCADE,
    date_posted DATE NOT NULL DEFAULT CURRENT_DATE,
    title VARCHAR(300) NOT NULL,
    content TEXT NOT NULL
);

CREATE TABLE APPLICANTS (
    id INT REFERENCES JOBINVITATIONS(id) ON DELETE CASCADE,
    user_id INT REFERENCES USERS(id) ON DELETE CASCADE
)

CREATE TABLE MANAGERS (
    id INT REFERENCES JOBINVITATIONS(id) ON DELETE CASCADE,
    company VARCHAR(200) NOT NULL
)

CREATE TABLE FOLLOWERS (
    from_user INT NOT NULL REFERENCES USERS(id) ON DELETE CASCADE,
    to_user INT NOT NULL REFERENCES USERS(id) ON DELETE CASCADE,
    UNIQUE(from_user,to_user)
);

ALTER TABLE FOLLOWERS
ADD CONSTRAINT not_equal CHECK (from_user != to_user);

CREATE FUNCTION add_user(firstname VARCHAR(255), lastname VARCHAR(255), email VARCHAR(255), age integer) RETURNS VOID AS $$ 
BEGIN 
    INSERT INTO users (first_name , last_name ,email, age) VALUES (firstname, lastname, email, age); 
END; $$ 
LANGUAGE PLPGSQL;

CREATE FUNCTION add_posts(auth_id integer, title_p VARCHAR(255), content_p TEXT) RETURNS VOID AS $$ 
BEGIN 
    INSERT INTO POST (author_id, title, content) VALUES (auth_id, title_p, content_p);
END; $$
LANGUAGE PLPGSQL;

CREATE FUNCTION follow(id1 integer, id2 integer) RETURNS VOID AS $$ 
BEGIN 
    INSERT INTO FOLLOWERS(from_user, to_user) VALUES (id1, id2);
END; $$
LANGUAGE PLPGSQL;

CREATE FUNCTION unfollow(id1 integer, id2 integer) RETURNS VOID AS $$ 
BEGIN 
    DELETE FROM FOLLOWERS WHERE from_user = id1 AND to_user = id2;
END; $$
LANGUAGE PLPGSQL;


CREATE OR REPLACE FUNCTION post_count_update_function() 
RETURNS TRIGGER AS 
$BODY$
BEGIN 
    UPDATE USERS SET 
    num_posts = num_posts + 1
    WHERE id = NEW.author_id;

    RETURN NEW;
END;
$BODY$
LANGUAGE PLPGSQL;

CREATE TRIGGER post_count_update_trigger
AFTER INSERT ON POST 
FOR EACH ROW EXECUTE PROCEDURE post_count_update_function();


CREATE OR REPLACE FUNCTION follow_count_update_function() 
RETURNS TRIGGER AS 
$BODY$
BEGIN 
    UPDATE USERS SET 
    followers = followers + 1
    WHERE id = NEW.to_user;
    UPDATE USERS SET 
    followings = followings + 1
    WHERE id = NEW.from_user;
    RETURN NEW;
END;
$BODY$
LANGUAGE PLPGSQL;

CREATE TRIGGER follow_count_update_trigger
AFTER INSERT ON FOLLOWERS 
FOR EACH ROW EXECUTE PROCEDURE follow_count_update_function();



