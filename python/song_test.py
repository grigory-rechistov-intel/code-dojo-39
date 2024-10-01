import unittest

from song import Thing, lyrics, sequence

expected_song = """There was an old lady who swallowed a fly.
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a spider;
That wriggled and wiggled and tickled inside her.
She swallowed the spider to catch the fly;
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a bird;
How absurd to swallow a bird.
She swallowed the bird to catch the spider,
She swallowed the spider to catch the fly;
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a cat;
Fancy that to swallow a cat!
She swallowed the cat to catch the bird,
She swallowed the bird to catch the spider,
She swallowed the spider to catch the fly;
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a dog;
What a hog, to swallow a dog!
She swallowed the dog to catch the cat,
She swallowed the cat to catch the bird,
She swallowed the bird to catch the spider,
She swallowed the spider to catch the fly;
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a cow;
I don't know how she swallowed a cow!
She swallowed the cow to catch the dog,
She swallowed the dog to catch the cat,
She swallowed the cat to catch the bird,
She swallowed the bird to catch the spider,
She swallowed the spider to catch the fly;
I don't know why she swallowed a fly - perhaps she'll die!

There was an old lady who swallowed a horse...
...She's dead, of course!"""


class Test(unittest.TestCase):
    def test_characterization(self):
        self.maxDiff = 5000
        self.assertEqual(lyrics().split("\n"), expected_song.split("\n"))


class TestSequence(unittest.TestCase):
    def test_sequence_of_none(self):
        things = ("1", "2")
        self.assertEqual("", sequence(things, 0))

    def test_sequence_of_one(self):
        things = (Thing("1", "spice1"), Thing("2", "spice2"))
        self.assertEqual(
            "She swallowed the 2 to catch the 1", sequence(things, 1)
        )

    def test_sequence_of_two(self):
        things = (
            Thing("1", "spice1"),
            Thing("2", "spice2"),
            Thing("3", "spice3"),
        )
        self.assertEqual(
            [
                "She swallowed the 3 to catch the 2,",
                "She swallowed the 2 to catch the 1",
            ],
            sequence(things, 2).split("\n"),
        )


if __name__ == "__main__":
    unittest.main()
