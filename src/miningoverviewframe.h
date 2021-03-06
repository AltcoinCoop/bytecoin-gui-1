#ifndef MININGOVERVIEWFRAME_H
#define MININGOVERVIEWFRAME_H

#include <QFrame>

class QAbstractItemModel;
class QDataWidgetMapper;

namespace Ui {
class MiningOverviewFrame;
}

namespace WalletGUI {

class MiningManager;
class WalletModel;

class MiningOverviewFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MiningOverviewFrame(QWidget *parent = 0);
    ~MiningOverviewFrame();

    void setMiningManager(MiningManager* miningManager);
    void setMinerModel(QAbstractItemModel* model);
    void setWalletModel(QAbstractItemModel* model);

    void miningStarted();
    void miningStopped();
    void activeMinerChanged(quintptr minerIndex);

    Q_SLOT void startMiningClicked();

private:
    Ui::MiningOverviewFrame *ui;

    MiningManager* miningManager_;
//    WalletModel* walletModel_;
    QDataWidgetMapper* miningMapper_;
//    QDataWidgetMapper* stateMapper_;
    bool started_;
};

}

#endif // MININGOVERVIEWFRAME_H
