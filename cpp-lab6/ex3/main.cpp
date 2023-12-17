#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Vec2D
{
public:
  Vec2D(double x = 0, double y = 0) : x_{x}, y_{y} {}

    void binSerialiseTo(const char* fileName){
        std::ofstream text(fileName, ios_base::binary);
        std::srand(1);
        double x = (rand() % 1000) / 10;
        double y = (rand() % 1000) / 10;
        Vec2D v(x, y);
        text << v << std::endl;
        text.close();
    }
    static Vec2D binDeserialiseFrom(const char* fileName){
        Vec2D v;
        std::ifstream text(fileName, ios_base::binary);
        text.read((char*)&v, sizeof(Vec2D));
        text.close();
        return v;
    }
    int getX()const{
        return x_;
    }
    int getY()const{
        return y_;
    }

private:
  double x_;
  double y_;
  friend ostream& operator<<(ostream&, const Vec2D&);
};

ostream& operator<<(ostream& out, const Vec2D& v)
{
  out << "[" << v.x_ << "," << v.y_ << "]";
  return out;
}

void writeIntoBinFileDemo(const char* fileName, const vector<Vec2D>& vecOfV2D)
{
  ofstream out(fileName, ios_base::binary);
  if (!out) {
    cout << "Cannot open file " << fileName << endl;
    return;
  }

  for (auto v : vecOfV2D) {
    out.write(reinterpret_cast<char*>(&v), sizeof(v));
  }

  out.close();
}

void readFromBinFileDemo(const char* fileName, vector<Vec2D>& vecOfV2D)
{
  std::ifstream in(fileName, ios_base::binary);
  if (!in) {
    cout << "Cannot open file " << fileName << endl;
    return;
  }

  Vec2D v;
  while (in.read(reinterpret_cast<char*>(&v), sizeof(v))) {
    vecOfV2D.emplace_back(v);
  }

  in.close();
}

void vectorGenerator(const char* file, int num_of_instances){
    ofstream text(file, ios_base::binary);
    std::srand(1);
    for(int i = 0; i < num_of_instances; i++){
        double x = (rand() % 1000) / 10;
        double y = (rand() % 1000) / 10;
        Vec2D v(x, y);
        text.write((char*)&v, sizeof(Vec2D));
    }
    text.close();
}

void readPositiveVectors(const char* file1, const char* file_res){
    ifstream text1(file1, ios_base::binary);
    ofstream text_res(file_res, ios_base::binary);
    Vec2D curr_vec;
    while(text1.read((char*)&curr_vec, sizeof(Vec2D))){
        if(curr_vec.getX() > 0 && curr_vec.getY() > 0){
            text_res.write((char*)&curr_vec, sizeof(Vec2D));
        }
    }
    text1.close();
    text_res.close();
}

bool isPositive(int num){
    return num > 0;
}

void readPositiveVectorsWithPredicate(const char* file1, const char* file_res,bool (*predicate)(int)){
    ifstream text1(file1, ios_base::binary);
    ofstream text_res(file_res, ios_base::binary);
    Vec2D curr_vec;
    while(text1.read((char*)&curr_vec, sizeof(Vec2D))){
        if(predicate(curr_vec.getX()) && predicate(curr_vec.getY())){
            text_res.write((char*)&curr_vec, sizeof(Vec2D));
        }
    }
    text1.close();
    text_res.close();
}

int main()
{
  vector<Vec2D> vecOfV2D1 {
    Vec2D{1.2, 2.3},
    Vec2D{1.23, 4.56},
    Vec2D{12.345, 67.890}
  };

  const char* fName = "vec2D.dat";
  writeIntoBinFileDemo(fName, vecOfV2D1);

  vector<Vec2D> vecOfV2D2;
  readFromBinFileDemo(fName, vecOfV2D2);

  for (auto v : vecOfV2D2) {
    cout << v << endl;
  }

  return 0;
}
