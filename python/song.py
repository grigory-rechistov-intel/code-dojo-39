song = """There was an old lady who swallowed a fly.
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

def _first_line(animal):
    return f"There was an old lady who swallowed a {animal};"
def _last_line():
    return "I don't know why she swallowed a fly - perhaps she'll die!"

# She swallowed the spider to catch the fly;
def sequence(animals):
    arr = []
    animals = ["fly"] + animals
    animals = list(reversed(animals))
    for i in range(len(animals)-1):
        arr.append(f"She swallowed the {animals[i]} to catch the {animals[i+1]}")
    ret = ",\n".join(arr)
    return ret+";"

def produce():
    animals = ["spider", "bird", "cat", "dog", "cow"]

    return f"""There was an old lady who swallowed a fly.
I don't know why she swallowed a fly - perhaps she'll die!

{_first_line(animals[0])}
That wriggled and wiggled and tickled inside her.
{sequence(animals[:1])}
{_last_line()}

{_first_line(animals[1])}
How absurd to swallow a {animals[1]}.
{sequence(animals[:2])}
{_last_line()}

{_first_line(animals[2])}
Fancy that to swallow a {animals[2]}!
{sequence(animals[:3])}
{_last_line()}

{_first_line(animals[3])}
What a hog, to swallow a {animals[3]}!
{sequence(animals[:4])}
{_last_line()}

{_first_line(animals[4])}
I don't know how she swallowed a {animals[4]}!
{sequence(animals[:5])}
{_last_line()}

There was an old lady who swallowed a horse...
...She's dead, of course!"""

print(produce())
print(song)

song_lines = song.split("\n")
produce_lines = produce().split("\n")
for l1, l2 in zip(song_lines, produce_lines):
    if l1 != l2:
        print(">>>", l1)
        print("<<<", l2)


