class Asteroid
{
    private :
    int Width;
    int Lenght;
    int PosX;
    int PosY;

    public :
    void SetPosition(int PosX, int PosY);
    void SetSize(int Width, int Lenght);
    void Draw();
};

class SpaceShip
{
    private :
    int Width;
    int Lenght;
    int PosX;
    int PosY;

    public :
    void SetPosition(int PosX, int PosY);
    void SetSize(int Width, int Lenght);
    void Draw();
};

class Bullet
{
    private :
    int Width;
    int Lenght;
    int PosX;
    int PosY;

    public :
    void SetPosition(int PosX, int PosY);
    void SetSize(int Width, int Lenght);
    void Draw();
};

class PointCounter
{
    private :
    int Width;
    int Lenght;
    int PosX;
    int PosY;
    int Value;

    public :
    void SetPosition(int PosX, int PosY);
    void SetSize(int Width, int Lenght);
    void Draw();
    void GetPointCount(int Value);
};

class HealthCounter
{
    private :
    int Width;
    int Lenght;
    int PosX;
    int PosY;
    int Value;

    public :
    void SetPosition(int PosX, int PosY);
    void SetSize(int Width, int Lenght);
    void Draw();
    void UpdateHealth(int Value);
};