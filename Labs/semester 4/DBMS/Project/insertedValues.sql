create database upsideavenue;

use upsideavenue;

create table users (
    username VARCHAR(255) PRIMARY KEY,
    password VARCHAR(255) not null,
    accountname VARCHAR(255) not null,
    phonenumber VARCHAR(255) not null,
    email VARCHAR(255),
    role VARCHAR(255) not null
);

CREATE TABLE properties (
    property_id int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    property_name VARCHAR(255),
    owner VARCHAR(255),
    FOREIGN KEY (owner) REFERENCES users(username),
    property_type VARCHAR(255),
    property_size int,
    bedrooms INT,
    furnished VARCHAR(255),
    house_number int,
    street varchar(255),
    city varchar(255),
    state varchar(255),
    zip_code int
);

create table posts (
    post_id int NOT NULL AUTO_INCREMENT PRIMARY KEY, 
    property_id int, 
    agent_id varchar(255),
    post_date date, 
    mode varchar(10), 
    price int, 
    post_status varchar(255), 
    description varchar(255),
    FOREIGN KEY (property_id) REFERENCES properties(property_id),
    FOREIGN KEY (agent_id) REFERENCES users(username)
);

create table sales(
    post_id int,
    seller_id VARCHAR(255),
    buyer_id VARCHAR(255),
    sale_date date, 
    PRIMARY KEY(post_id),
    FOREIGN KEY (post_id) REFERENCES posts(post_id),
    FOREIGN KEY (seller_id) REFERENCES users(username),
    FOREIGN KEY (buyer_id) REFERENCES users(username)
);

CREATE TABLE chat(
    chat_id int NOT NULL AUTO_INCREMENT PRIMARY KEY,
    post_id int,
    sender VARCHAR(255),
    receiver VARCHAR(255),
    sent_time TIMESTAMP,
    message VARCHAR(255),
    FOREIGN KEY (post_id) REFERENCES posts(post_id),
    FOREIGN KEY (sender) REFERENCES users(username),
    FOREIGN KEY (receiver) REFERENCES users(username)
);

CREATE TABLE photos(
    property_id int,
    photo_id INT,
    PRIMARY KEY (property_id,photo_id),
    FOREIGN KEY (property_id) REFERENCES properties(property_id),
    photo longblob
);


-- Insert into users table
INSERT INTO users (username, password, accountname, phonenumber, email, role)
VALUES
  ('john_smith', 'password123', 'John Smith', '+1-123-456-7890', 'john.smith@example.com', 'user'),
  ('jane_doe', 'password456', 'Jane Doe', '+1-234-567-8901', 'jane.doe@example.com', 'user'),
  ('bob_johnson', 'password789', 'Bob Johnson', '+1-345-678-9012', 'bob.johnson@example.com', 'user'),
  ('samantha_lee', 'password234', 'Samantha Lee', '+1-456-789-0123', 'samantha.lee@example.com', 'user'),
  ('chris_chen', 'password567', 'Chris Chen', '+1-567-890-1234', 'chris.chen@example.com', 'agent'),
  ('sam_smith', 'password789', 'Sam Smith', '555-2468', 'samsmith@example.com', 'agent'),
  ('amy_adams', 'passwordABC', 'Amy Adams', '555-1357', 'amyadams@example.com', 'user'),
  ('mike_miller', 'passwordXYZ', 'Mike Miller', '555-3691', 'mikemiller@example.com', 'user'),
  ('mike_williams', 'abc123', 'Mike Williams', '555-9012', 'mikewilliams@hotmail.com', 'agent'),
  ('linda_harris', 'mypwd', 'Linda Harris', '555-3456', 'linda.harris@gmail.com', 'user'),
  ('david_smith', 'password', 'David Smith', '555-7890', 'davidsmith@yahoo.com', 'agent');
  ('chinda_ronit', 'Chinda@###', 'Ronit Chinda', '7988224882', 'ronitchinda100@gmail.com', 'admin');
  
-- Insert into properties table
INSERT INTO properties (property_name, owner, built_year,property_type, property_size, bedrooms, furnished, house_number, street, city, state, zip_code)
VALUES
('Cozy Cottage', 'linda_harris',2010, 'House', 1200, 2, 'Unfurnished', 123, 'Main St', 'LA', 'NY', 12345),
('Modern Condo', 'jane_doe',2020, 'Condo', 900, 1, 'Furnished', 456, 'Broadway', 'Cityville', 'CA', 54321),
('Luxury Apartment', 'john_smith',2022, 'Apartment', 1500, 3, 'Furnished', 789, 'Park Ave', 'Metropolis', 'IL', 67890),
('Rustic Cabin', 'bob_johnson',2019, 'House', 800, 2, 'Unfurnished', 234, 'Pine St', 'Ruralville', 'WA', 45678),
('Charming Bungalow', 'mike_miller',2022, 'House', 1100, 2, 'Furnished', 567, 'Lakeview Dr', 'Suburbia', 'OH', 23456),
('City Loft', 'john_smith',2011, 'Apartment', 1200, 2, 'Unfurnished', 890, '5th Ave', 'Bigcity', 'NY', 78901),
('Seaside Villa', 'jane_doe',1999, 'House', 2000, 4, 'Furnished', 321, 'Ocean Blvd', 'Beachtown', 'CA', 56789),
('Mountain Chalet', 'bob_johnson',2015, 'House', 1500, 3, 'Furnished', 654, 'Snowy Rd', 'Mountainside', 'CO', 34567),
('Spacious Duplex', 'amy_adams',2021, 'House', 1800, 4, 'Unfurnished', 987, 'Grove St', 'Ruraltown', 'TX', 45678),
('Country Farmhouse', 'john_smith',2023, 'House', 2500, 4, 'Furnished', 123, 'Farm Rd', 'Ruraltown', 'MN', 23456),
('Downtown Studio', 'jane_doe',2022, 'Apartment', 600, 1, 'Furnished', 456, 'Main St', 'Bigcity', 'NY', 78901),
('Lakefront Cottage', 'bob_johnson',2020, 'House', 900, 2, 'Unfurnished', 789, 'Lakeshore Dr', 'Laketown', 'MI', 45678),
('Beach House', 'jane_doe',2021, 'House', 1200, 3, 'Furnished', 234, 'Beach Ave', 'Beachtown', 'CA', 56789),
('Urban Townhouse', 'john_smith',2020, 'Townhouse', 1400, 3, 'Furnished', 567, 'Broadway', 'Bigcity', 'NY', 78901),
('Ski Lodge', 'samantha_lee',2000, 'House', 1800, 4, 'Furnished', 890, 'Mountain Rd', 'Skitown', 'CO', 201102),
('Victorian Mansion', 'bob_johnson',2011, 'House', 3500, 5, 'Furnished', 321, 'Main St', 'Historictown', 'PA', 54312);


-- Insert into post table
INSERT INTO posts (property_id, agent_id, post_date, mode, price, post_status, description)
VALUES
(1, 'chris_chen', '2022-01-03', 'Rent', 1500, 'Active', 'Cozy cottage available for rent.'),
(2, 'sam_smith', '2021-02-02', 'Sale', 250000, 'Active', 'Modern condo for sale.'),
(3, 'david_smith', '2020-01-03', 'Rent', 3000, 'Active', 'Luxury apartment for rent.'),
(4, 'mike_williams', '2023-01-04', 'Sale', 175000, 'Active', 'Rustic cabin for sale.'),
(5, 'david_smith', '2022-01-05', 'Rent', 2000, 'Active', 'Charming bungalow available for rent.'),
(6, 'mike_williams', '2021-02-06', 'Sale', 500000, 'Active', 'City loft for sale.'),
(7, 'chris_chen', '2018-08-07', 'Rent', 4000, 'Active', 'Seaside villa available for rent.'),
(8, 'mike_williams', '2023-02-08', 'Sale', 400000, 'Inactive', 'Mountain chalet for sale.'),
(9, 'david_smith', '2023-03-09', 'Rent', 3500, 'Inactive', 'Spacious duplex available for rent.'),
(10, 'chris_chen', '2021-01-10', 'Sale', 750000, 'Inactive', 'Country farmhouse for sale.');



INSERT INTO sales(post_id,seller_id,buyer_id,sale_date)
VALUES
(8, 'bob_johnson', 'linda_harris','2022-01-20'),
(9, 'david_smith', 'jane_doe','2022-01-11'),
(10, 'chris_chen', 'samantha_lee','2022-02-10');

