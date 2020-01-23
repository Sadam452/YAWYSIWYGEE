#ifndef TYPESETLINE_H
#define TYPESETLINE_H

#include "phrase.h"

#include <QBrush>

namespace Typeset{

class Line : public Phrase{
public:
    Line* prev;
    Line* next;
    uint32_t line_num;

private:
    QGraphicsSimpleTextItem line_num_box;

public:
    Line(Text* f = nullptr, Text* b = nullptr, uint32_t line_num = 1);
    void repositionLineNumber();
    void repositionNextLine();
    void renumberLine(uint32_t n);
    void setLineNumberVisible(bool show);
    virtual void updateTheme() override final;
    virtual void updateToTop() override final;
    virtual Text* textRight() const override final;
    virtual Text* textLeft() const override final;
    virtual Text* textRightUp() const override final;
    virtual Text* textLeftUp() const override final;
    virtual Text* textUp(qreal x) const override final;
    virtual Text* textDown(qreal x) const override final;
    virtual bool isLine() const override final;
    virtual Line& getLine() override final;
    void unfocusLineNumber();
    void focusLineNumber();
    bool proceeds(Line& l);
    bool proceedsInclusive(Line& l);
    virtual void populateMenu(QMenu&) override final;
    virtual void write(QTextStream& out) const override final;

protected:
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override final;
    virtual QRectF boundingRect() const override final;

private:
    void updateLineboxNumber();
};

void link(Line* a, Line* b);

}

#endif // TYPESETLINE_H
