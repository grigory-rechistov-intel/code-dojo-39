from dataclasses import dataclass


@dataclass
class Thing:
    name: str
    spice: str


def intro(thing: Thing) -> str:
    return f"There was an old lady who swallowed a {thing.name}"


def first_verse(things: list[Thing]) -> list[str]:
    return [
        intro(things[0]) + ".",
        things[0].spice,
    ]


def middle_verse(things: list[Thing], i: int) -> list[str]:
    return [
        intro(things[i]) + ";",
        things[i].spice,
        sequence(things, amount=i) + ";",
        things[0].spice,
    ]


def last_verse(things: list[Thing]) -> list[str]:
    return [
        intro(things[-1]) + "...",
        things[-1].spice,
    ]


def verse(things: list[Thing], i):
    if i == 0:
        return first_verse(things)

    if 1 <= i < len(things) - 1:
        return middle_verse(things, i)

    if i == len(things) - 1:
        return last_verse(things)


def sequence(things, amount):
    if amount == 0:
        return ""

    things = list(reversed(things))
    text = []
    for first, second in zip(things[-amount - 1 :], things[-amount:]):
        text.append(
            "She swallowed the %s to catch the %s" % (first.name, second.name)
        )
    return ",\n".join(text)


things_to_swallow = [
    Thing("fly", "I don't know why she swallowed a fly - perhaps she'll die!"),
    Thing("spider", "That wriggled and wiggled and tickled inside her."),
    Thing("bird", "How absurd to swallow a bird."),
    Thing("cat", "Fancy that to swallow a cat!"),
    Thing("dog", "What a hog, to swallow a dog!"),
    Thing("cow", "I don't know how she swallowed a cow!"),
    Thing("horse", "...She's dead, of course!"),
]


def lyrics():
    verses = []
    for i in range(0, len(things_to_swallow)):
        verses.append("\n".join(verse(things_to_swallow, i)))
    return "\n\n".join(verses)


def main():
    print(lyrics())


if __name__ == "__main__":
    main()
