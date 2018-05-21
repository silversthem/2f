#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <2f.hpp>

class Weapon;

// Bullet data
struct BulletData {
  sf::Vector2i coords;
  int orientation;
  float dcoef; // How distance affects damage
  float pcoef; // How well it can penetrate walls and stuff
  Weapon *origin; // What shot that bullet
};

// Bullet
class Bullet : public f2::Projectile<BulletData> {
  void update(int const& nt) {
    // Checking for collision
    origin->update_bullet(&data);
  }
};

// Bullet container
typedef f2::indexers::ObjectSet<BulletData,Bullet> Bullets;

// Interface for things that can be shot
class Weapon_Target {

};

// Interface for things that can shoot
class Weapon_Shooter {

};

// Interface for weapons
class Weapon {
protected:
  /* Weapon attributes */
  int rateOfFire;

public:
  /* Weapon virtual methods */
  virtual void update_bullet(BulletData* bd) { // Updates bullet depending on weapon

  }
};

/* Types of weapon */

class Gun {

};

class Rifle {

};

/* Weapons */

class Handgun {

};

class AK {

};

#endif
