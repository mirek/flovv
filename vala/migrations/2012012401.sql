begin transaction;

create table migrations (
    version string
);

create table patches (
    id int,
    name string,
    identifier string
);

create table settings(
    patch_id int,
    key string,
    value data
);

create table connections(
    source_patch_id int,
    output string,
    destination_patch_id int,
    input string
);

insert into migrations values("2012012401");

commit transaction;
