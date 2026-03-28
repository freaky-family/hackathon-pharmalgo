#!/usr/bin/env bash

# ffmpeg -i rickroll-roll.mp4 -vf fps=10 output/out%d.png

transform() {
    convert $1 -resize 24x24 -monochrome $1.converted
}

FILES=./output/*.png

for f in $FILES
do
    # echo $f
    transform $f
#   DO STUFF
done


