#ifndef DIE_H
#define DIE_H

class Die {

private:
    int m_sides;
    int m_die_value;

public:
    Die();
    Die(int S);
    void set_die_value();
    int get_die_value();
};

#endif //DIE_H
