import os
from PIL import Image, ImageFont, ImageDraw
from moviepy.editor import *
FONTNAME = "LiberationSans-Bold.ttf"
FONTSIZE = 90

def getSize(txt, font):
    testImg = Image.new('RGB', (1, 1))
    testDraw = ImageDraw.Draw(testImg)
    return testDraw.textsize(txt, font)


if __name__ == '__main__':
    text = "Да, мы можем"

    colorText = "black"
    colorBackground = "white"
    font = ImageFont.truetype(FONTNAME, FONTSIZE)
    width, height = getSize(text, font)
    img = Image.new('RGB', (width+100, 100), colorBackground)
    d = ImageDraw.Draw(img)
    d.text((5, -8), text, fill=colorText, font=font)
    img.save("string.jpg")

    im = Image.open('string.jpg')

    if not os.path.isdir("images"):
        os.mkdir("images")
    img_clips = []
    step = int((width - 90) / 59)
    offset = (width - 90) % 58
    first_count_step = 60 - offset
    for i in range(first_count_step):
        im_crop = im.crop((step*i, 0, 100 + step*i, 100))
        im_crop.save(f'images/image{i}.jpg', quality=95)
        slide = ImageClip(f'images/image{i}.jpg', duration=0.05)
        img_clips.append(slide)
    stop_place = step*first_count_step
    step += 1
    for i in range(first_count_step, 60):
        im_crop = im.crop((stop_place+(step*(i-first_count_step)), 0, (stop_place+100+step*(i-first_count_step)),
                           100))
        im_crop.save(f'images/image{i}.jpg', quality=95)
        slide = ImageClip(f'images/image{i}.jpg', duration=0.05)
        img_clips.append(slide)
    video_slides = concatenate_videoclips(img_clips, method='compose')
    video_slides.write_videofile("runstring.mp4", fps=60)
