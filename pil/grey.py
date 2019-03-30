from convert import *

bali = open_image('bali.jpg')

a = convert_halftoning(bali)

a.save('a.png', 'png')