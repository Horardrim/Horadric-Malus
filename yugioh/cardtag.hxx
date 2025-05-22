#ifndef CARD_TAG_HXX
#define CARD_TAG_HXX


struct card_tag
{

};

struct magic_card : public card_tag
{

};

struct trap_card : public card_tag
{

};

struct monster_card : public card_tag
{

};

struct effect_monster_card : public monster_card
{

};

#endif
