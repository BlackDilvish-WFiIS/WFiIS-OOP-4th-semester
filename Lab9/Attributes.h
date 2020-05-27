#pragma once
//Dostepne atrybuty dla wypisywanego tekstu

//Klasa reprezentujaca rodzaj formatu dla tekstu
class AttFormat
{
public:
    //Dostepne rodzaje formatu tekstu
    enum Attribute{
        BOLD,
        DIM,
        UNDERLINED,
        NORMAL,
    };

    AttFormat(AttFormat::Attribute format)
        : m_format(format) {}
        
    virtual ~AttFormat() = default;
    
    AttFormat::Attribute getFormat() const { return m_format; }
    void setFormat(AttFormat::Attribute format) { m_format = format; }
    
private:
    AttFormat::Attribute m_format;
};

//Klasa reprezentujaca kolor wypisywanego tekstu
class AttColor
{
public:
    //Dostepne kolory
    enum Attribute{
        BLACK,
        RED,
        GREEN, 
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        GRAY,
        WHITE,
    };

    AttColor(AttColor::Attribute color)
        : m_color(color) {}
        
    virtual ~AttColor() = default;
    
    AttColor::Attribute getColor() const { return m_color; }
    void setColor(AttColor::Attribute col) { m_color = col; }
    
private:
    AttColor::Attribute m_color;
};