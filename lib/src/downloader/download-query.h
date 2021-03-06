#ifndef DOWNLOAD_QUERY_H
#define DOWNLOAD_QUERY_H

#include <QJsonObject>
#include <QString>


class Profile;
class Site;

class DownloadQuery
{
	protected:
		// Constructors
		DownloadQuery() = default;
		explicit DownloadQuery(Site *site);
		explicit DownloadQuery(Site *site, QString filename, QString path);

	public:
		virtual ~DownloadQuery() = default;

		// Serialization
		virtual void write(QJsonObject &json) const = 0;
		virtual bool read(const QJsonObject &json, Profile *profile) = 0;

		// Public members
		Site *site;
		QString filename;
		QString path;
};

#endif // DOWNLOAD_QUERY_H
