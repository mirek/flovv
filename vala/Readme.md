## Overview

__floVv__ is node based engine for creative coding similar to Quartz Composer written in Vala.

## Installation and Usage

Vala 15.x compiler is required. It won't work with 14.x as we're using collections which were moved from `Gee` namespace in 14.x to `Vala` namespace in 15.x

On OSX install Vala using homebrew:

	brew install vala
	brew install glew
	brew install sqlite3

If you see error similar to ``, make sure you've got X11 installed, you can grab it from http://xquartz.macosforge.org/landing

On Ubuntu Linux I had to add Vala source (info at https://launchpad.net/~vala-team/+archive/ppa) to install Vala 15.x compiler.

To create `flovv` executable:

	make

There's two ways to run compositions:

1. `./flovv examples/nbody/nbody.sql` - will create in-memory database, run all migrations and provided composition sql
2. `./flovv examples/nbody/nbody.db` - will run sqlite composition

To create composition file from .sql file run all migrations and import composition .sql file:

    sqlite3 composition.db < migrations/*.sql
	sqlite3 composition.db < examples/nbody/nbody.sql

## Participate

The best way to contribute is to add your own patches. Similar to Quartz Composer we've got three type of patches:

* Provider - ie. Mouse...
* Processor - ie. Sine, Multiply...
* Consumer - ie. NBody, Triangle...

Clone the project in github, have a look at patches (`patch` directory), choose one you think is the closest to your new patch and copy it.
After committing send pull request.

## Internals

Currently `.db` composition file is just a plain sqlite3 database. This file format is perfect, we can easily add new patches, create connections and change settings. To see the current schema of sqlite3 composition file have a look at `migrations` directory.

## Examples

<center>
	<img src="https://github.com/mirek/floVv/raw/master/examples/cloud/cloud.png" alt="test001.flovv" width="50%" height="50%" />
	<img src="https://github.com/mirek/floVv/raw/master/examples/nbody/nbody.png" alt="test002-nbody.flovv" width="50%" height="50%" />
</center>

## Released under LGPL v3 License

	floVv node based engine for creative coding
	Copyright (C) 2012 Mirek Rusin <mirek [at] me [dot] com>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
