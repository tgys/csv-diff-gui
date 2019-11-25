#ifndef SESSION_H
#define SESSION_H


#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>

class sessionData : public QSharedData
{
public:
    QString fileonepath;
    QString filetwopath;
    int tablesloaded;
    QHash<QString, int> fileonecolumns;
    QHash<QString, int> filetwocolumns;
    QHash<QString, QString> equivalents;
    QHash<QString, QString> modified;
    QList<QString> uniquekeys;
};

class Session
{
  public:
    Session() { d = new sessionData; d->tablesloaded = 0; }
    Session(QString &onepath, QString &twopath) {
        d = new sessionData;
        setFileOnePath(onepath);
        setFileTwoPath(twopath);
    }

    void setFileOnePath(const QString &path) {
        d->fileonepath = path;
    }
    void setFileTwoPath(const QString &path) {
        d->filetwopath = path;
    }

    void addCol_one(QString &str, int i) { d->fileonecolumns[str] = i; }
    const QStringList returnCols_one() {return d->fileonecolumns.keys(); }
    int getColNum_one(QString &col) { return d->fileonecolumns[col]; }
    void clearCols_one() { d->fileonecolumns.clear(); }

    void addCol_two(QString &str, int i) { d->filetwocolumns[str] = i; }
    int getColNum_two(QString &col) { return d->filetwocolumns[col]; }
    const QStringList returnCols_two() {return d->filetwocolumns.keys(); }
    void clearCols_two() { d->filetwocolumns.clear(); }

    int sizeofColsOne() { return d->fileonecolumns.size(); }
    int sizeofColsTwo() { return d->filetwocolumns.size(); }

    QString getFileOnePath() const { return d->fileonepath; }
    QString getFileTwoPath() const { return d->filetwopath; }

    QString getEquivalent(QString &str) const {return d->equivalents[str]; }
    QHash<QString, QString> returnEquivalents() { return d->equivalents; }
    void setEquivalent(QString &first, QString &second) { d->equivalents[first] = second; }
    void clearEquivalent() { d->equivalents.clear(); }

    QString getModified(QString &str) const {return d->modified[str]; }
    QHash<QString, QString> returnModified() { return d->modified; }
    void setModified(QString &first, QString &second) { d->modified[first] = second; }

    bool inUniqueKeys(QString &col) { return d->uniquekeys.contains(col); }
    void addUniqueKey(QString &key) { d->uniquekeys.append(key); }
    void clearUniqueKeys() {d->uniquekeys.clear(); }
    QList<QString> returnUniqueKeys() { return d->uniquekeys; }
    void removeUniqueKey(QString &key) { d->uniquekeys.removeAll(key); }

    void incTablesLoaded() {
        if (d->tablesloaded < 2) { d->tablesloaded++; }
    }
    int getTablesLoaded() const {return d->tablesloaded; }

  private:
    QSharedDataPointer<sessionData> d;
};


#endif // SESSION_H
