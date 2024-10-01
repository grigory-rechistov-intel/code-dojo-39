def verse(things, killer, i):
    if i == 0:
        return [
            "There was an old lady who swallowed a %s." % things[i],
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[i],
        ]

    if i == 1:
        return [
            "There was an old lady who swallowed a %s;" % things[i],
            "That wriggled and wiggled and tickled inside her.",
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[0]
        ]

    if i == 2:
        return [
            "There was an old lady who swallowed a %s;" % things[i],
            "How absurd to swallow a %s." % things[i],
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[0]
        ]

    if i == 3:
        return [
            "There was an old lady who swallowed a %s;" % things[i],
            "Fancy that to swallow a %s!" % things[i],
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[0],
        ]

    if i == 4:
        return [
            "There was an old lady who swallowed a %s;" % things[i],
            "What a hog, to swallow a %s!" % things[i],
            "She swallowed the %s to catch the %s," % ("dog", "cat"),
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[0],
        ]

    if i == 5:
        return [
            "There was an old lady who swallowed a %s;" % things[i],
            "I don't know how she swallowed a %s!" % things[i],
            "She swallowed the %s to catch the %s," % ("cow", "dog"),
            "She swallowed the %s to catch the %s," % ("dog", "cat"),
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % things[0]
        ]

    if i == 6:
        return [
            "There was an old lady who swallowed a %s..." % killer,
            "...She's dead, of course!",
        ]

def sequence(things, amount):
    text = ""
    for (first, second) in zip(things[:amount+1], things[1:amount+1]):
        text += "She swallowed the %s to catch the %s,\n" % (second, first)
    return text

def song():
    killer = "horse"
    things_to_swollow = ["fly", "spider", "bird", "cat", "dog", "cow"]
    verses = []
    for i in range(0,7):
        verses.append("\n".join(verse(things_to_swollow, killer, i)))
    return "\n\n".join(verses)

def lyrics():
  return song()

def main():
  print(lyrics())

if __name__ == '__main__':
  main()
