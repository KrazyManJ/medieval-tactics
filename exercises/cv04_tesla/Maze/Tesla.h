#ifndef WORM_H
#define WORM_H


class Tesla {
private:
    int x;
    int y;
    int energy;
public:
    Tesla(const int x, const int y);
    static const char symbol = 'T';
    static const int ENERGY_DEFAULT = 10;
    int getX() const;
    int getY() const;
    int getEnergy() const;
    void moveTo(const int x, const int y);
    void charge();
};


#endif //UNTITLED_WORM_H
