#ifndef COLORBLOCK_H
#define COLORBLOCK_H

//#include <QLabel>

class ColorBlock : public QLabel
{
	Q_OBJECT

public:
	ColorBlock(QWidget *parent);
	~ColorBlock();

	void SetColor(const QColor &clrBg);
};

#endif // COLORBLOCK_H
