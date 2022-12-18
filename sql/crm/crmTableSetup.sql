# refresh database

drop table if exists clientInfo;

drop table if exists customerIndustry;

drop table if exists customerInfo;

drop table if exists industry;

drop table if exists orderContent;

drop table if exists salesOrder;

drop table if exists client;

drop table if exists customer;

drop table if exists userAddress;

drop table if exists userInfo;

drop table if exists timeZone;

drop table if exists user;



create table timeZone(
  id int not null auto_increment,
  abbreviation varchar(2) not null ,
  primary key (id)
);


##################################################
-- user
##################################################
create table user (
  id int not null auto_increment,
  username varchar(45) not null,
  password varchar(500) not null,
  primary key (id)
);

-- bijection exists, fk can be used as pk
create table userInfo (
    id int not null,
    email varchar(45) not null,
    fName varchar(45) not null,
    lName varchar(45) not null,
    phoneNumber int not null,
    timeZoneId int not null,
    primary key (id),
    foreign key (id) references user(id)
        on delete cascade,
    foreign key (timeZoneId) references timeZone(id)
);
-- require users to have an address, name, method of contact
create table userAddress (
    id int not null,
    userId int not null,
    state varchar(2) not null , #allow for abbreviated name only
    city varchar(45) not null ,
    zip int not null ,
    streetName varchar(45) not null,
    streetNumber int not null,
    suite int,
    primary key (id),
    foreign key(userId) references user(Id)
        on delete cascade
);


#####################################################
# Industry
#####################################################

create table industry(
    id int not null auto_increment,
    type varchar(45),
    primary key (id)
);

######################################################
# customer / client
######################################################

create table customer(
    id int not null auto_increment,
    name varchar(50),
    primary key (id)
);

create table client(
    id int not null auto_increment,
    employerId int not null ,
    primary key (id),
    foreign key (employerId) references customer(id)
);


# bijection between info and customer
create table customerInfo(
  id int not null,
  country varchar(45) not null,
  provinceOrState varchar(2) not null,
  postalCode int not null,
  streetName varchar(45) not null ,
  streetNumber int not null ,
  primaryRepId int,
  foreign key (id) references customer(id),
  primary key (id),
  foreign key (primaryRepId) references client(id)

);

# bijection between info and client
create table clientInfo(
    id int not null,
    fName varchar(45) not null ,
    lName varchar(45) not null ,
    phone int not null ,
    timeZoneId int not null,
    foreign key (id) references client(id),
    primary key (id),
    foreign key (timeZoneId) references timeZone(id)
);

# allows customer to have multiple industries
# ie mitsubishi chemical would be plastics, pharmaceuticals,
# carbon products, etc.
create table customerIndustry(
    customerId int not null,
    industryId int not null,
    foreign key (customerId) references customer(id),
    foreign key (industryId) references industry(id)
);

########################################################
# orders
########################################################

create table salesOrder(
  id int not null auto_increment,
  salesPersonId int not null,
  clientId int not null,
  primary key (id),
  foreign key (salesPersonId) references user(id),
  foreign key (clientId) references client(id)
);

create table orderContent(
  id int not null,
  productId int not null , # retrieve from erp
  foreign key (id) references salesOrder(id)
);