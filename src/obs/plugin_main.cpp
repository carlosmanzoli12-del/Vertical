#include <obs-module.h>
#include <obs-frontend-api.h>
#include <QDockWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("streamforge", "en-US")

namespace {
QDockWidget *streamforgeDock = nullptr;

QWidget *createDockContents()
{
    auto *root = new QWidget();
    auto *layout = new QVBoxLayout(root);
    auto *heading = new QLabel(QObject::tr("StreamForge"));
    QFont headingFont = heading->font();
    headingFont.setPointSize(16);
    headingFont.setBold(true);
    heading->setFont(headingFont);

    auto *description = new QLabel(QObject::tr("Central de transmissões para OBS Studio 30.0.2"));
    description->setWordWrap(true);
    auto *twitchStatus = new QLabel(QObject::tr("Twitch: não conectada"));
    auto *tiktokStatus = new QLabel(QObject::tr("TikTok: não conectada"));
    auto *outputStatus = new QLabel(QObject::tr("Transmissões: ainda não iniciadas"));
    auto *connectTwitch = new QPushButton(QObject::tr("Conectar Twitch"));
    auto *connectTikTok = new QPushButton(QObject::tr("Conectar TikTok"));
    auto *startButton = new QPushButton(QObject::tr("Iniciar multistream"));
    auto *stopButton = new QPushButton(QObject::tr("Parar multistream"));
    startButton->setEnabled(false);
    stopButton->setEnabled(false);

    auto *notice = new QLabel(QObject::tr(
        "Integração nativa inicial. OAuth e mecanismo de saídas múltiplas "
        "serão habilitados nas próximas etapas."));
    notice->setWordWrap(true);

    layout->addWidget(heading);
    layout->addWidget(description);
    layout->addSpacing(8);
    layout->addWidget(twitchStatus);
    layout->addWidget(connectTwitch);
    layout->addWidget(tiktokStatus);
    layout->addWidget(connectTikTok);
    layout->addSpacing(8);
    layout->addWidget(outputStatus);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    layout->addSpacing(8);
    layout->addWidget(notice);
    layout->addStretch();
    return root;
}
} // namespace

bool obs_module_load(void)
{
    if (streamforgeDock)
        return true;
    streamforgeDock = new QDockWidget(QStringLiteral("StreamForge"));
    streamforgeDock->setObjectName(QStringLiteral("StreamForgeDock"));
    streamforgeDock->setWidget(createDockContents());
    if (!obs_frontend_add_dock_by_id("streamforge.main", "StreamForge", streamforgeDock)) {
        delete streamforgeDock;
        streamforgeDock = nullptr;
        blog(LOG_ERROR, "[StreamForge] Could not register the OBS dock.");
        return false;
    }
    blog(LOG_INFO, "[StreamForge] Native OBS dock loaded.");
    return true;
}

void obs_module_unload(void)
{
    obs_frontend_remove_dock("streamforge.main");
    streamforgeDock = nullptr;
    blog(LOG_INFO, "[StreamForge] Native OBS dock unloaded.");
}
