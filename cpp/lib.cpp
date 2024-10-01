#include "lib.h"
#include <vector>
#include <format>
using std::string;
using std::format;

class Animal;
using Sequence = std::vector<Animal *>;

class Animal {
    protected:
    string name;
    string intro_punctuation;
    public:
    virtual ~Animal() {};
    const string get_name() const {return name;}
    Animal() = delete;
    Animal(const string _name) {
        name = _name;
        intro_punctuation = ";";
    }
    virtual const string verse_intro() {
        const string lady_intro = "There was an old lady who swallowed";
        string res = format("{} a {}", lady_intro, name);
        return res + intro_punctuation + '\n';
    }
    virtual const string verse_comment() = 0;
    virtual const string verse_conclusion() = 0;
    virtual const string reason_to_swallow(const Animal *prey) = 0;
    virtual const string separator() {return ",\n";}
    virtual const string swallow_sequence(const Sequence animals, size_t depth) = 0;
};


class StartingAnimal: public Animal {
    public:
    StartingAnimal(const string _name): Animal(_name) {
        intro_punctuation = ".";
    }
    virtual const string verse_comment() {
        return "";
    }
    virtual const string verse_conclusion() {
        return "";
    }
    virtual const string reason_to_swallow(const Animal *prey) {
        return format(
            "I don't know why she swallowed a {} - perhaps she'll die!\n",
                name);
    }
    virtual const string separator() {return ";\n";};

    virtual const string swallow_sequence(const Sequence animals, size_t depth) {
        return reason_to_swallow(nullptr);
    }
};

class RescueAnimal: public Animal {
    string comment;
    public:
    RescueAnimal(const string _name, const string _comment):
        Animal(_name), comment(_comment) {}
    virtual const string verse_comment() {
        return comment;
    }
    virtual const string verse_conclusion() {
        return "";
    }
    virtual const string reason_to_swallow(const Animal *prey) {
        return format("She swallowed the {} to catch the {}", name, prey->get_name());
    }
    virtual const string swallow_sequence(const Sequence animals, size_t depth) {
        auto prey = depth > 0? animals.at(depth - 1): nullptr;
        auto line = reason_to_swallow(prey);
        string separator = prey->separator();
        return line + separator + prey->swallow_sequence(animals, depth-1);
    }

};

class LethalAnimal: public Animal {
    public:
    LethalAnimal(const string _name): Animal(_name) {
        intro_punctuation = "...";
    }
    virtual const string verse_comment() {
        return "";
    }
    virtual const string verse_conclusion() {
        return "...She's dead, of course!";
    }
    virtual const string reason_to_swallow(const Animal *prey) {
        return "";
    }
    virtual const string swallow_sequence(const Sequence animals, size_t depth) {
        return reason_to_swallow(nullptr);
    }
};

class NullAnimal: public Animal {
    public:
    NullAnimal(const string _name): Animal(_name) {}
    virtual const string verse_intro() {
        return "";
    }
    virtual const string verse_comment() {
        return "";
    }
    virtual const string verse_conclusion() {
        return "";
    }
    virtual const string reason_to_swallow(const Animal *prey) {
        return "";
    }
    virtual const string separator() {return "";};
    virtual const string swallow_sequence(const Sequence animals, size_t depth) {
        return "";
    }
};

class Song {
    Sequence animals;
    public:
    Song() = delete;
    Song(Sequence _animals): animals(_animals) {};
    ~Song() {
        for (Animal *a: animals) {
            delete a;
        }
    }

    Animal * get_animal(Sequence &animals, size_t n) {
        static auto na = NullAnimal("");
        if (n >= animals.size()) {
            return &na;
        }
        return animals.at(n);
    }

    const string get_verse(size_t n)
    {
        auto animal = get_animal(animals, n);
        auto verse = animal->verse_intro() + animal->verse_comment() +
            animal->swallow_sequence(animals, n) + animal->verse_conclusion();

        return verse;
    }

    const string get_continuation(size_t starting_verse)
    {
        auto verse = get_verse(starting_verse);
        if (verse.size() == 0) {
            return verse;
        }
        return verse + "\n" + get_continuation(starting_verse + 1);
    }

};

Song make_classic_sequence() {
    auto fly = new StartingAnimal("fly");
    auto spider = new RescueAnimal("spider", "That wriggled and wiggled and tickled inside her.\n");
    auto bird = new RescueAnimal("bird", "How absurd to swallow a bird.\n");
    auto cat = new RescueAnimal("cat", "Fancy that to swallow a cat!\n");
    auto dog = new RescueAnimal("dog", "What a hog, to swallow a dog!\n");
    auto cow = new RescueAnimal("cow", "I don't know how she swallowed a cow!\n");
    auto horse = new LethalAnimal("horse");
    return Song({fly, spider, bird, cat, dog, cow, horse});
}

const string chop_final_newline(string in)
{
    if (in.back() == '\n') {
        in.pop_back();
    }
    return in;
}

const string get_song()
{
    auto classic_song = make_classic_sequence();
    return chop_final_newline(classic_song.get_continuation(0));
}

const string get_silly_song()
{
    auto bug = new StartingAnimal("bug");
    auto slug = new RescueAnimal("slug", "It hid in her mug.\n");
    auto crocodile = new LethalAnimal("crocodile");
    Song silly({bug, slug, crocodile});
    return(silly.get_continuation(0));
}
