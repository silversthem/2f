#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

#define OUTDIR "textures/player"
#define PATH "textures/Top_Down_Survivor"
#define PREFIX "survivor-"
#define FILETYPE ".png"

#define HBOX 210
#define LINES 5

std::vector<std::string> get_files(std::string cl,std::string sp, int amount) {
  std::vector<std::string> files;
  for(int i = 0;i < amount;i++) {
    std::stringstream s;
    s << PATH << "/" << cl << "/" << sp << "/" << PREFIX << sp << "_" << i << FILETYPE;
    files.push_back(s.str());
  }
  return files;
}

bool create_texture(std::vector<std::string> files,std::string output, int x, int y, int amount, int lines) {
  int cols = amount/lines;
  sf::Texture t;
  t.create(x*(cols+1),y*(lines+1));
  int posx,posy;
  for(int i = 0;i < amount;i++) {
    sf::Image img;
    img.loadFromFile(files[i]);
    posx = i % cols;
    posy = i/cols;
    t.update(img,x*posx,posy*y);
  }
  sf::Image out = t.copyToImage();
  out.saveToFile(output);
  return true;
}

int main() {

  std::vector<std::string> classes;
  classes.push_back("feet");

  std::vector<std::string> sprites;
  sprites.push_back("run");
  sprites.push_back("strafe_left");
  sprites.push_back("strafe_right");
  sprites.push_back("walk");

  int amounts[] = {20,20,20,20};

  for(int i = 0;i < classes.size();i++) {
    for(int j = 0;j < sprites.size();j++) {
      std::stringstream filename;
      filename << OUTDIR << "/" << classes[i] << "/" << sprites[j] << FILETYPE;
      create_texture(get_files(classes[i],sprites[j],amounts[j]),filename.str(),HBOX,HBOX,amounts[j],LINES);
    }
  }

  return 0;
}
