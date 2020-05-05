#ifndef GLOBALS_H
#define GLOBALS_H

#include "MathBran/include/QMathBran_Macros.h"
#include <QFontDatabase>
#include <QPen>

#include <QDebug>
#define DO_THIS(message) \
    qDebug() << "DO THIS: " << message << ", file " << __FILE__ << " line " << __LINE__;

#include <QMessageBox>
#define FATAL_ERROR(message) {\
    QMessageBox messageBox; \
    messageBox.critical(nullptr, "Error", QString("Fatal Error: ") + message); \
    messageBox.setFixedSize(500,200); \
    exit(0);}

static constexpr qreal line_vspace = 4;
static constexpr qreal linebox_offet = 10;

class Globals{
    public:
        static bool vertical_integrals;
        static QPen empty_box_pen;

        static QFont bigqchar_font;
        static QFontMetrics bigqchar_font_metrics;
        static QFont integral_font;
        static QFontMetrics integral_font_metrics;
        static QFont word_font;
        static QFontMetrics word_font_metrics;
        static constexpr uint8_t deepest_script_level = 2;
        static constexpr int font_sizes[deepest_script_level+1] = {15, 12, 11};
        static QFont fonts[deepest_script_level+1];
        static QFontMetrics font_metrics[deepest_script_level+1];
        static QFont passive_linenum_font;
        static QFont active_linenum_font;
        static QFontMetrics passive_linenum_font_metrics;
        static QFontMetrics active_linenum_font_metrics;
        static void initGlobals();
};

#endif // GLOBALS_H
