from dataclasses import dataclass


@dataclass
class Thing:
    name: str
    spice: str


def intro(thing: Thing) -> str:
    return f"There was an old lady who swallowed a {thing.name}"


def verse(things: list[Thing], killer: Thing, i):
    if i == 0:
        return [
            intro(things[i]) + ".",
            things[i].spice,
        ]

    if i == 1:
        return [
            intro(things[i]) + ";",
            things[i].spice,
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            things[0].spice,
        ]

    if i == 2:
        return [
            intro(things[i]) + ";",
            things[i].spice,
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            things[0].spice,
        ]

    if i == 3:
        return [
            intro(things[i]) + ";",
            things[i].spice,
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            things[0].spice,
        ]

    if i == 4:
        return [
            intro(things[i]) + ";",
            things[i].spice,
            "She swallowed the %s to catch the %s," % ("dog", "cat"),
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            things[0].spice,
        ]

    if i == 5:
        return [
            intro(things[i]) + ";",
            things[i].spice,
            "She swallowed the %s to catch the %s," % ("cow", "dog"),
            "She swallowed the %s to catch the %s," % ("dog", "cat"),
            "She swallowed the %s to catch the %s," % ("cat", "bird"),
            "She swallowed the %s to catch the %s," % ("bird", "spider"),
            "She swallowed the %s to catch the %s;" % ("spider", "fly"),
            things[0].spice,
        ]

    if i == 6:
        return [
            intro(killer) + "...",
            killer.spice,
        ]


def sequence(things, amount):
    text = ""
    for first, second in zip(things[: amount + 1], things[1 : amount + 1]):
        text += "She swallowed the %s to catch the %s,\n" % (second, first)
    return text


killer = Thing("horse", "...She's dead, of course!")
things_to_swollow = [
    Thing("fly", "I don't know why she swallowed a fly - perhaps she'll die!"),
    Thing("spider", "That wriggled and wiggled and tickled inside her."),
    Thing("bird", "How absurd to swallow a bird."),
    Thing("cat", "Fancy that to swallow a cat!"),
    Thing("dog", "What a hog, to swallow a dog!"),
    Thing("cow", "I don't know how she swallowed a cow!"),
]


def song():
    verses = []
    for i in range(0, 7):
        verses.append("\n".join(verse(things_to_swollow, killer, i)))
    return "\n\n".join(verses)


def lyrics():
    return song()


def main():
    print(lyrics())


if __name__ == "__main__":
    main()
