# refresh database
drop table if exists clientContact;

drop table if exists clientInfo;

drop table if exists customerIndustry;

drop table if exists customerInfo;

drop table if exists industry;

drop table if exists orderContent;

drop table if exists salesOrder;

drop table if exists client;

drop table if exists customer;

drop table if exists territoryStateProvince;

drop table if exists stateProvince;

drop table if exists country;

drop table if exists territory;

drop table if exists userAddress;

drop table if exists userContact;

drop table if exists userInfo;

drop table if exists timeZone;

drop table if exists user;


################################################
# timezone
################################################

create table timeZone(
  id int not null auto_increment,
  abbreviation varchar(2) not null ,
  primary key (id)
);

###################################################
# Country
###################################################

create table country(
  id int not null auto_increment,
  fullName varchar(50) not null ,
  abbreviation varchar(2) not null ,
  primary key (id)
);

##################################################
# stateProvince
##################################################
create table stateProvince(
   id int not null auto_increment,
   countryId int not null ,
   fullName varchar(50) not null ,
   abbreviation varchar(2) not null ,
   foreign key (countryId) references country(id),
   primary key (id)
);


##################################################
# user
##################################################
create table user (
  id int not null auto_increment,
  username varchar(45) not null unique , # make sure admin
                                        # and client dne with
                                        # username
  password varchar(500) not null,
  primary key (id)
);

-- bijection exists, fk can be used as pk
create table userInfo (
    id int not null,
    fName varchar(45) not null,
    lName varchar(45) not null,
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
    stateProvince varchar(2) not null , #allow for abbreviated name only
    city varchar(45) not null ,
    postalCode int not null ,
    streetName varchar(45) not null,
    streetNumber int not null,
    suite int,
    primary key (id),
    foreign key(userId) references user(Id)
        on delete cascade
);

create table userContact(
  id int not null ,
  phoneCountryCode int not null ,
  phoneAreaCode int not null ,
  phoneNumber int not null ,
  altPhoneCountryCode int,
  altPhoneAreaCode int,
  altPhoneNumber int,
  email varchar(45) not null,
  foreign key (id) references user(id),
  primary key (id)
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
    name varchar(50) ,
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
    foreign key (id) references client(id),
    primary key (id)
);

create table clientContact(
    id int not null,
    phone int not null,
    email varchar(50) not null ,
    timeZoneId int not null ,
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
  salesTotal int not null,
  primary key (id),
  foreign key (salesPersonId) references user(id),
  foreign key (clientId) references client(id)
);

create table orderContent(
  id int not null,
  productId int not null , # retrieve from erp
  qty int not null,
  qtySaleValue int not null , # derived from erp
  primary key (id),
  foreign key (id) references salesOrder(id)
);

########################################################
# sales territories
########################################################

create table territory(
  id int not null auto_increment,
  salesPersonId int not null, # non-unique allows multiple
                              #salespersons per territory
  primary key (id),
  foreign key (salesPersonId) references user(id)
);

create table territoryStateProvince(
    id int not null auto_increment,
    territoryId int not null ,
    stateProvinceId int not null,
    foreign key (territoryId) references territory(id),
    foreign key (stateProvinceId) references stateProvince(id),
    primary key (id)
);