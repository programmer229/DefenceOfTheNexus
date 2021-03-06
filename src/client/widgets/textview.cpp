#include <QDebug>

#include "../../utils/lang.h"

#include "textview.h"

client::TextView::TextView(const QPoint& position, const QString& text, const QFont& font,
                           const QColor& color,
                           int height, int width):
        Widget(position), text(text), font(font), color(color) {
    setHeight(height);
    setWidth(width);
}

void client::TextView::paint(QPainter& painter) {
    painter.setFont(font);
    QPen pen = painter.pen();
    pen.setColor(color);
    painter.setPen(pen);
    if (width > 0 && height > 0) {
        painter.drawText(QRect(0, 0, width, height), Qt::AlignCenter, getDrawingText());
    } else {
        painter.drawText(QPoint(0, 0), getDrawingText());
    }
}

const QString& client::TextView::getText() const {
    return text;
}

void client::TextView::setText(const QString& text) {
    TextView::text = text;
}

const QFont& client::TextView::getFont() const {
    return font;
}

void client::TextView::setFont(const QFont& font) {
    TextView::font = font;
}

const QColor& client::TextView::getColor() const {
    return color;
}

void client::TextView::setColor(const QColor& color) {
    TextView::color = color;
}

void client::TextView::setTextSize(int textSize) {
    font.setPixelSize(textSize);
}

int client::TextView::getTextSize() const {
    return font.pixelSize();
}

int client::TextView::getTextHeight() const {
    return QFontMetrics(font).capHeight();
}

int client::TextView::getTextWidth() const {
    return QFontMetrics(font).width(getDrawingText());
}

QString client::TextView::getDrawingText() const {
    QString drawingText = text;
    if (text.startsWith("::")) {
        drawingText = utils::Lang::get(text.right(text.size() - 2));
    }
    return drawingText;
}
