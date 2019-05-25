import turtle


silly = turtle.Turtle()
silly.speed(0)
silly.width(5)

def square():
    '''nobody likes me but I make a square. It's cool , I think but like... yeah'''
    silly.color('red')
    silly.forward(50)
    silly.right(90)     # Rotate clockwise by 90 degrees

    silly.forward(50)
    silly.right(90)

    silly.color('green')
    silly.forward(50)
    silly.right(90)

    silly.forward(50)
    silly.right(90)

def leaf(c):
    silly.color(c)
    silly.left(45)
    silly.circle(200, steps=9)

def leaf_canada(c):
    silly.color(c)
    silly.left(45)
    silly.circle(400, steps=9)

def flower_layer(c1, c2):
    leaf(c1)
    leaf(c2)
    leaf(c1)
    leaf(c2)

def flower_layer_canada(c1, c2):
    leaf_canada(c1)
    leaf_canada(c2)
    leaf_canada(c1)
    leaf_canada(c2)

rainbow = [
    '#e6261f',
    '#eb7532',
    '#f7d038',
    '#a3e048',
    '#a3e048',
    '#34bbe6',
    '#4355db',
    '#c224a5',
]

def canada(palette):
    for color in palette:
        flower_layer_canada(color, color)
        silly.left(1)

def merica(palette):
    for color in palette:
        flower_layer(color, color)
        silly.left(1)

for i in range(15):
    canada(rainbow)
    merica(rainbow)


turtle.done()