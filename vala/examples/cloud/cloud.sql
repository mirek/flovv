
insert into patches(id, name, identifier) values (1, "mouse", "mouse[0]");
insert into patches(id, name, identifier) values (2, "fps", "fps[0]");
insert into patches(id, name, identifier) values (3, "frame", "frame[0]");
insert into patches(id, name, identifier) values (4, "sine", "sine[0]");
insert into patches(id, name, identifier) values (5, "cloud", "cloud[0]");
insert into patches(id, name, identifier) values (6, "multiply", "multiply[0]");

insert into connections(source_patch_id, output, destination_patch_id, input) values (1, "out-x", 5, "in-rotate-y");
insert into connections(source_patch_id, output, destination_patch_id, input) values (1, "out-y", 5, "in-rotate-x");

insert into connections(source_patch_id, output, destination_patch_id, input) values (3, "out-frame", 6, "in-a");
insert into settings(patch_id, key, value) values(6, "in-b", 0.0025);
insert into connections(source_patch_id, output, destination_patch_id, input) values (6, "out-value", 4, "in-x");

insert into connections(source_patch_id, output, destination_patch_id, input) values (4, "out-sine", 5, "in-r");
