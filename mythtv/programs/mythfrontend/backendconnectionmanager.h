#include <QObject>

class Reconnect;
class QTimer;
class QEvent;

class BackendConnectionManager : public QObject
{
    Q_OBJECT

  public:
    BackendConnectionManager();
    ~BackendConnectionManager();

    void customEvent(QEvent*) override; // QObject

  protected slots:
    void ReconnectToBackend(void);

  protected:
    Reconnect *m_reconnecting;
    QTimer    *m_reconnect_timer;
    bool       m_reconnect_again;
};
