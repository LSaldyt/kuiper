import sfml as sf

print(dir(sf.window))
print(dir(sf.audio))
print(dir(sf.graphics))
print(dir(sf.network))
print(dir(sf.system))
1/0

def main():
    window = sf.window(sf.VideoMode(640, 480),
                             'Drawing an image with SFML')
    window.framerate_limit = 60
    running = True
    texture = sf.Texture.load_from_file('python-logo.png')
    sprite = sf.Sprite(texture)

    while running:
        for event in window.iter_events():
            if event.type == sf.Event.CLOSED:
                running = False

        if sf.Keyboard.is_key_pressed(sf.Keyboard.RIGHT):
            sprite.move(5, 0)
        elif sf.Keyboard.is_key_pressed(sf.Keyboard.LEFT):
            sprite.move(-5, 0)

        window.clear(sf.Color.WHITE)
        window.draw(sprite)
        window.display()

    window.close()


if __name__ == '__main__':
    main()
