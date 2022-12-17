#Refresh the database if tables exist

drop table if exists distributorInfo;

drop table if exists distributorRep;

drop table if exists distributorRepInfo;

drop table if exists product;

drop table if exists recipeMaterial;

drop table if exists material;

drop table if exists distributor;

drop table if exists recipe;

drop table if exists spec;

drop table if exists userAddress;

drop table if exists userInfo;

drop table if exists user;




##################################################
# user
##################################################
create table user (
  id int not null auto_increment,
  username varchar(45) not null,
  password varchar(500) not null,
  primary key (id)
);

# bijection exists, fk can be used as pk
create table userInfo (
    id int not null,
    email varchar(45) not null,
    fName varchar(45) not null,
    lName varchar(45) not null,
    phoneNumber int not null,
    primary key (id),
    foreign key (id) references user(id)
        on delete cascade
);
# require users to have an address, name, method of contact
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

##########################################################
# distributor
##########################################################

create table distributor(
  id int not null auto_increment,
  name varchar(100) not null,
  primary key (id)
);

create table distributorInfo(
    id int not null,
    country varchar(2),
    provinceOrState varchar(2),
    timeZone varchar(2),
    openHour time,
    closeHour time,
    primary key (id),
    foreign key (id) references distributor(id)
);

#-----------------  distributor rep --------------------

create table distributorRep (
    id int not null auto_increment,
    employerId int not null,
    primary key (id),
    foreign key (employerId) references distributor(id)
);

create table distributorRepInfo (
    id int not null,
    fName varchar(45) not null ,
    lName varchar(45) not null ,
    email varchar(45) not null ,
    phone int not null,
    deptName varchar(45)
);


#########################################################
# material / recipe
#########################################################
create table material(
  id int not null auto_increment,
  name varchar(45) not null ,
  distributorId int not null,
  alternateDistributorId int,
  description varchar(500) not null,
  notes varchar(150),
  primary key (id),
  foreign key(distributorId) references distributor(id),
  foreign key (alternateDistributorId) references distributor(id)
);

create table spec(
  id int not null auto_increment,
  schematic blob not null ,
  details varchar(5000) not null ,
  primary key (id)
);

create table recipe(
  id int not null auto_increment,
  name varchar(45),
  description varchar(500) not null ,
  specId int not null,
  primary key (id),
  foreign key (specId) references spec(id)
);

# to get multivalued attribute will make a new recipe
# by taking highest current val and increasing by 1
create table recipeMaterial(
  id int not null,
  recipeId int not null,
  materialId int not null,
  foreign key (recipeId) references recipe(id),
  foreign key (materialId) references material(id)
);

######################################################
# product
######################################################
create table product(
    id int not null,
    img blob, #if null we'll use a placeholder img
    description varchar(1000) not null,
    recipeId int not null,
    currentCount int not null,
    primary key(id),
    foreign key (recipeId) references recipe(id)
);

