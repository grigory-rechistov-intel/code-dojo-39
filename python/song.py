def verse(i):
    if i == 0:
        return [
            "There was an old lady who swallowed a fly.",
            "I don't know why she swallowed a fly - perhaps she'll die!",
        ]

    if i == 1:
        return [
            "There was an old lady who swallowed a spider;",
            "That wriggled and wiggled and tickled inside her.",
            "She swallowed the spider to catch the fly;",
            "I don't know why she swallowed a fly - perhaps she'll die!"
        ]

    if i == 2:
        return [
            "There was an old lady who swallowed a bird;",
            "How absurd to swallow a bird.",
            "She swallowed the bird to catch the spider,",
            "She swallowed the spider to catch the fly;",
            "I don't know why she swallowed a fly - perhaps she'll die!"
        ]

    if i == 3:
        return [
            "There was an old lady who swallowed a cat;",
            "Fancy that to swallow a cat!",
            "She swallowed the cat to catch the bird,",
            "She swallowed the bird to catch the spider,",
            "She swallowed the spider to catch the fly;",
            "I don't know why she swallowed a fly - perhaps she'll die!"
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
            "There was an old lady who swallowed a cow;",
            "I don't know how she swallowed a cow!",
            "She swallowed the cow to catch the dog,",
            "She swallowed the dog to catch the cat,",
            "She swallowed the cat to catch the bird,",
            "She swallowed the bird to catch the spider,",
            "She swallowed the spider to catch the fly;",
            "I don't know why she swallowed a fly - perhaps she'll die!",
        ]

    if i == 6:
        return [
            "There was an old lady who swallowed a horse...",
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
