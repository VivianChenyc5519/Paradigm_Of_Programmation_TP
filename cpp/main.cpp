//
// main.cpp
// Created on 21/10/2018
//
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"
#include <iostream>
#include <sstream>
#include <memory>
#include "tcpserver.h"

using namespace std;
using mmPtr = std::shared_ptr<Multimedia>;
using pPtr = std::shared_ptr<Photo>;
using vPtr = std::shared_ptr<Video>;
using fPtr = std::shared_ptr<Film>;
using gPtr = std::shared_ptr<Group>;
const int PORT = 3331;

// #define VERSION_1

int main(int argc, const char *argv[])
{
#ifdef VERSION_1
  /*TEST multimedia project*/
  // Multimedia * m = new Multimedia("test", "test");
  // const std::string name = m->getName();
  // m->display(std::cout);
  // unsigned int count = 2;
  // Multimedia **medias = new Multimedia *[count];

  /* TEST for display*/
  // for (unsigned int i = 0; i < count; i++)
  // {
  //     if (i % 2)
  //     {
  //         medias[i] = new Photo();
  //     }
  //     else
  //     {
  //         medias[i] = new Video();
  //     }
  // }
  // for (unsigned int j = 0; j < count; j++){
  //     medias[j]->display(std::cout);
  // }

  /*TEST for play*/
  // medias[0] = new Photo("test-photo",
  //                       "/home/vivian_withana/paradigm/TP1/test-photo.JPG",
  //                       0, 0);
  // medias[1] = new Video("test-video",
  //                       "/home/vivian_withana/paradigm/TP1/test-video.mp4",
  //                       10);
  // for (unsigned int i = 0; i < count - 1; i++)
  // {
  //     medias[i]->play();
  // }

  /*TEST for film*/
  // Film *f1 = new Film("Toy Story", "./ToyStory", 20, nullptr, 0);
  // int chap_num = 5;
  // int *chapters = new int[chap_num]{10, 20, 30, 40, 50};
  // f1->setChapters(chapters, chap_num);
  // f1->display(std::cout);

  /*Delete the original chapters to test deep copy*/
  // delete[] chapters;
  // std::cout << "After deleting original chapters..\n";
  // f->display(std::cout);
  // delete[] medias;

  /* TEST for copy */
  // Film *f2 = new Film("Story", "./Story", 20, nullptr, 5);
  // int chap_num2 = 8;
  // int *chapters2 = new int[chap_num2]{10,20,30,40,50,60,70,80};
  // f2->setChapters(chapters2,chap_num2);
  // *f1 = *f2;
  // for (size_t i = 0; i < f1->getChapterNumber(); ++i){
  //     std::cout << "Chapter " << i << " has duration" <<
  //     f1->getChapters()[i] << "\n";
  // }
  // std::cout << "f1 addr "<< f1 << "\n";
  // std::cout << "f2 addr "<< f2 << "\n";
  // delete[] chapters2;
  // delete[] chapters;

  /* TEST for group class */
  // int* chapters1 = new int[5]{10,20,30,40,50};
  // mmptr p1 = make_shared<Photo>(
  //     "test-photo",
  //     "/home/vivian_withana/paradigm/TP1/test-photo.JPG",
  //     0, 0);
  // mmptr f1 = make_shared<Film>("Story", "./Story", 20,
  //     chapters1, 5);
  // mmptr f2 = make_shared<Film>("Toy Story", "./ToyStory", 20,
  //     chapters1, 5);

  // Group *g1 = new Group();
  // g1->push_back(p1);

  // g1->push_back(f1);
  // g1->push_back(f2);
  // g1->setName("My favorites");
  // g1->display(std::cout);
  // Group *g2 = new Group();
  // g2->push_back(f1);
  // g2->push_back(f2);
  // g2->setName("My second group");

  // f1.reset(); // decrease the reference count for f1
  // std::cout << "After resetting f1\n";
  // g1->display(std::cout);
  // g2->display(std::cout);
  // delete g1;
  // std::cout << "After deleting g1\n";
  // g2->display(std::cout);
  // // delete f1;
  // // delete f2;
  // delete[] chapters1;
  // delete g2;

  /*TEST for map*/
  // Manager *m = new Manager();
  // pPtr photo = m->createPhoto("test-photo",
  //                             "/home/vivian_withana/paradigm/TP1/test-photo.JPG",
  //                             10, 10);
  // vPtr video = m->createVideo("test-video",
  //                             "/home/vivian_withana/paradigm/TP1/test-video.mp4",
  //                             10);
  // gPtr g = m->createGroup("My favorites");
  // g->push_back(photo);
  // g->push_back(video);
  // int chap_num = 5;
  // int *chapters = new int[chap_num]{10, 20, 30, 40, 50};
  // m->createFilm("Toy Story", "./ToyStory", 20, chapters, chap_num);
  // m->searchAndDisplay("test-photo", std::cout);
  // m->searchAndDisplay("test-video", std::cout);
  // // m->playMedia("test-photo");
  // m->playMedia("test-video");
  // m->deleteByName("test-photo");
  // m->searchAndDisplay("My favorites",std::cout);
  // m->deleteByName("My favorites");
  // delete m;
  // delete[] chapters;

  /* TEST for serialization */
  std::string f = "multimedias.txt";
  Manager *m1 = new Manager();
  try
  {
    pPtr photo = m1->createPhoto("test-photo",
                                 "/home/vivian_withana/paradigm/TP1/test-photo.JPG",
                                 10, 10);
    vPtr video = m1->createVideo("test-video",
                                 "/home/vivian_withana/paradigm/TP1/test-video.mp4",
                                 10);
    gPtr g = m1->createGroup("My favorites");
    g->push_back(photo);
    g->push_back(video);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return -1;
  }

  int chap_num = 5;
  int *chapters = new int[chap_num]{10, 20, 30, 40, 50};
  try
  {
    m1->createFilm("ToyStory", "./ToyStory", 20, chapters, chap_num);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  // write
  for (const auto &pair : m1->getMedias())
  {
    mmPtr media = pair.second;
    media->write(f);
  }
  // write
  Manager *m2 = new Manager();
  m2->read(f);
  // for (const auto &pair : m2->getMedias())
  // {
  //   std::cout << pair.first << ": " << pair.second << std::endl;
  // }
  try
  {
    m2->searchAndDisplay("test-photo", std::cout);
    m2->searchAndDisplay("test-video", std::cout);
    m2->searchAndDisplay("ToyStory", std::cout);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  std::cout << "---Clean up----\n";
  delete m1;
  delete[] chapters;
  delete m2;
#else
  Manager *m = new Manager();
  gPtr g = nullptr;
  int chap_num = 5;
  int *chapters = new int[chap_num]{10, 20, 30, 40, 50};
  try
  {
    pPtr photo = m->createPhoto("test-photo",
                                "/home/vivian_withana/paradigm/TP1/test-photo.JPG",
                                10, 10);
    vPtr video = m->createVideo("test-video",
                                "/home/vivian_withana/paradigm/TP1/test-video.mp4",
                                10);
    g = m->createGroup("My favorites");
    g->push_back(photo);
    g->push_back(video);
    m->createFilm("ToyStory", "./ToyStory", 20, chapters, chap_num);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return -1;
  }
  auto *server = new TCPServer([&](std::string const &request, std::string &response)
                               {
      std::cout << "request: " << request << std::endl;
      std::stringstream ss(request);
      std::string action, name;
      ss >> action >> name;
      if (action == "search")
      {
        std::ostringstream oss;
        try
        {
          m->searchAndDisplay(name, oss);
        }
        catch(const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
        response = oss.str();
      } else {
        // std::stringstream ss;
          m->playMedia(name);
          // ss << "Playing "<<name;
          // response = ss.str();
      }
      std::cout << "response: " << response << std::endl;
      return true; });
  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0)
  {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  delete[] chapters;
  delete m;
  delete server;
#endif
  return 0;
}
