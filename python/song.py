def verse(i):
    if i == 0:
        return [
            "There was an old lady who swallowed a %s." % "fly",
            "I don't know why she swallowed a %s - perhaps she'll die!" % "fly",
        ]

    if i == 1:
        return [
            "There was an old lady who swallowed a %s;" % "spider",
            "That wriggled and wiggled and tickled inside her.",
            "She swallowed the spider to catch the %s;" % "fly",
            "I don't know why she swallowed a %s - perhaps she'll die!" % "fly"
        ]

    if i == 2:
        return [
            "There was an old lady who swallowed a %s;" % "bird",
            "How absurd to swallow a %s." % "bird",
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the spider to catch the %s;" % "fly",
            "I don't know why she swallowed a %s - perhaps she'll die!" % "fly"
        ]

    if i == 3:
        return [
            "There was an old lady who swallowed a cat;",
            "Fancy that to swallow a %s!" % "cat",
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a fly - perhaps she'll die!",
        ]

    if i == 4:
        return [
            "There was an old lady who swallowed a dog;",
            "What a hog, to swallow a dog!",
            "She swallowed the dog to catch the cat,",
            "She swallowed the cat to catch the bird,",
            "She swallowed the bird to catch the spider,",
            "She swallowed the spider to catch the fly;",
            "I don't know why she swallowed a fly - perhaps she'll die!",
        ]

    if i == 5:
        return [
            "There was an old lady who swallowed a %s;" % "cow",
            "I don't know how she swallowed a %s!" % "cow",
            "She swallowed the %s to catch the %s," % ("cow", "dog"),
            "She swallowed the %s to catch the %s," % ("dog", "cat"),
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            "I don't know why she swallowed a %s - perhaps she'll die!" % "fly",
        ]

    if i == 6:
        return [
            "There was an old lady who swallowed a %s..." % "horse",
            "...She's dead, of course!",
        ]


def song():
    verses = []
    for i in range(0,7):
        verses.append("\n".join(verse(i)))
    return "\n\n".join(verses)

def lyrics():
  return song()

def main():
  print(lyrics())

if __name__ == '__main__':
  main()
