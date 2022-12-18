# refresh database

drop table if exists adminAddress;

drop table if exists adminContact;

drop table if exists adminInfo;

drop table if exists admin;

drop table if exists timeZone;

#################################################
# time zone
#################################################

create table timeZone(
  id int not null auto_increment,
  abbreviation varchar(2) not null ,
  primary key (id)
);

#################################################
# Admin
#################################################

# Admin table, will be used for signup

create table admin(
  id int not null auto_increment,
  username varchar(45) not null unique,
  password varchar(500) not null,
  primary key (id)
);

create table adminContact(
    id int not null,
    email varchar(100) not null ,
    phone varchar(45),
    foreign key (id) references admin(id) ,
    primary key (id)
);

create table adminInfo(
  id int not null,
  fName varchar(45),
  lName varchar(45),
  foreign key (id) references admin(id) ,
  primary key (id)
);

create table adminAddress(
    id int not null,
    country varchar(2) not null ,
    stateProvince varchar(2) not null ,
    city varchar(45) not null ,
    streetNumber int not null ,
    streetName varchar(50) not null ,
    postalCode int not null ,
    suite int,
    timeZoneId int not null ,
    foreign key (id) references admin(id),
    primary key (id),
    foreign key (timeZoneId) references timeZone(id)
);