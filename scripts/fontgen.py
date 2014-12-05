from PIL import Image


img = Image.open('nesfont.png')
pix = img.load()

scale = 2

width, height = img.size
cw = width // 16 // scale
ch = height // 6 // scale
bw = (cw + 7) // 8

font = []
for y in range(0, height, ch * scale):
    for x in range(0, width, cw * scale):
        letter = []
        for l in range(ch):
            line = {'bytes': [], 'strings': []}
            for b in range(0, bw * 8, 8):
                byte = 0
                string = ''
                for p in range(8):
                    if pix[x + b + p * scale, y + l * scale] > 0:
                        byte += 2 ** (7 - p)
                        string += '#'
                    else:
                        string += ' '
                line['bytes'].append(byte)
                line['strings'].append(string)
            letter.append(line)
        font.append(letter)

count = 0
for a, letter in enumerate(font[:-1]):
    print("\t// @{} '{}' ({} pixels wide)".format(count, chr(32 + a), cw))
    for line in letter:
        print('\t{}// {}'.format(''.join(['0x{:02X}, '.format(byte) for byte in line['bytes']]),
                                 ''.join(line['strings'])))
    print()
    count += ch * bw
