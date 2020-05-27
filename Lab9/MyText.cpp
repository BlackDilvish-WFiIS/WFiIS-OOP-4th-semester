#include"MyText.h"

MyText::MyText(const std::string& text, AttFormat::Attribute format, AttColor::Attribute col)
    :  AttColor(col), AttFormat(format), m_text(text)
{
    
}