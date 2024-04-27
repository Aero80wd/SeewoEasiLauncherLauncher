#ifndef ANISHOW_LABEL_H
#define ANISHOW_LABEL_H
#include<QLabel>
#include<QPropertyAnimation>
#include<QGraphicsOpacityEffect>
#include<QRect>
#include<QPoint>
#endif // ANISHOW_LABEL_H
class AnimationLabel: public QLabel{
    Q_OBJECT
public:
    AnimationLabel(QWidget *parent = nullptr);
    ~AnimationLabel();
    void Anishow();
    void AniHide();
    int time = 700;
    void setTime(int secs){
        time = secs;
    }
    virtual void resizeEvent(QResizeEvent *event) override;
    QPropertyAnimation* ani_pos;
    QPropertyAnimation* ani_opty;
};
class AnimationLabelUp: public QLabel{
    Q_OBJECT
public:
    AnimationLabelUp(QWidget *parent = nullptr);
    ~AnimationLabelUp();
    void Anishow();
    void AniHide();
    int time = 700;
    void setTime(int secs){
        time = secs;
    }
    virtual void resizeEvent(QResizeEvent *event) override;
    QPropertyAnimation* ani_pos;
    QPropertyAnimation* ani_opty;
};
