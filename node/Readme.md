# Installation

`brew install anttweakbar` didn't work for me, if you find yourself having problems try:

    cd
    wget https://raw.github.com/davidcox/AntTweakBar/master/libanttweakbar.rb
    cp libanttweakbar.rb /usr/local/Library/Formula/
    brew install --HEAD libanttweakbar
    rm libanttweakbar.rb

(based on https://github.com/davidcox/AntTweakBar)

    brew install glfw
    npm install node-glfw

    brew install freeimage
    npm install node-webgl

    npm install sqlite3
