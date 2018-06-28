#ifndef _MISIL_
#define _MISIL_
	
class Misil {
protected:
	int x, y,n;
	int ancho, largo;
	int danio;
	string sprite;
	vector<int>nav;

public:
	Misil();
	~Misil();

	int Get_x();
	int Get_y();
	int Get_w();
	int Get_h();
	int Get_danio();
	vector<int> Get_nav();

	void Set_x(int x);
	void Set_y(int y);
	void Set_X_Y(int x, int y);
	void Set_w(int w);
	void Set_h(int h);
	void Set_danio(int danio);
	void Set_nav(vector<int>nav);


	void DibujarMisil(System::Drawing::Graphics^ g);
	virtual void Algoritmo();
};

Misil::Misil() 
{
	sprite = "Naves\\Misil_A.png";
}
Misil::~Misil() {}

int Misil::Get_x() { return this->x; }
int Misil::Get_y() { return this->y; }
int Misil::Get_w() { return this->ancho; }
int Misil::Get_h() { return this->largo; }
int Misil::Get_danio() { return this->danio; }
vector<int> Misil::Get_nav() {	return this->nav; }


void Misil::Set_x(int x) { this->x = x; }
void Misil::Set_y(int y) { this->y = y; }
void Misil::Set_X_Y(int x, int y) { this->x = x; this->y = y; }
void Misil::Set_w(int w) { this->ancho = w; }
void Misil::Set_h(int h) { this->largo = h; }
void Misil::Set_danio(int danio) { this->danio = danio; }
void Misil::Set_nav(vector<int>nav) { this->nav=nav; }

//void Misil::Algoritmo() { return; }

void Misil::DibujarMisil(System::Drawing::Graphics^ g)
{
	Bitmap^ img = gcnew Bitmap(gcnew String(sprite.c_str()));
	img->MakeTransparent(img->GetPixel(0, 0));
	g->DrawImage(img, x, y, ancho, largo);
	delete img;
}

inline void Misil::Algoritmo()
{
}

#endif // !_MISIL_
