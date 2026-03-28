#!/usr/bin/env python3
# /// script
# dependencies = [
#   "Pillow",
# ]
# ///

from PIL import Image

files = [
    "output/out15.png.converted",
    "output/out21.png.converted",
    "output/out7.png.converted",
    "output/out12.png.converted",
    "output/out6.png.converted",
    "output/out20.png.converted",
    "output/out10.png.converted",
    "output/out8.png.converted",
    "output/out17.png.converted",
    "output/out16.png.converted",
    "output/out9.png.converted",
    "output/out5.png.converted",
    "output/out2.png.converted",
    "output/out14.png.converted",
    "output/out3.png.converted",
    "output/out11.png.converted",
    "output/out13.png.converted",
    "output/out4.png.converted",
    "output/out1.png.converted",
    "output/out19.png.converted",
    "output/out18.png.converted",
]

for file in files:
    im = Image.open(file)

    rgb_im = im.convert('RGB')
    width, height = rgb_im.size

    with open(file.replace(".converted", ".pharma"), "w+") as f:
        for y in range(height):
            for x in range(width):
                r, g, b = rgb_im.getpixel((x, y))

                if r == 0 and g == 0 and b == 0:
                    f.write(".")
                else:
                    f.write("x")
                # print(x, y, r, g, b)
            f.write("\n")

