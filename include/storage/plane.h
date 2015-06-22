#ifndef PLANE_H
#define PLANE_H

#include <vector>
#include <map>

namespace Storage {

class Hit;
class Cluster;

/**
  * Collection of hits and clusters from the same sensor plane. Note that the
  * hits and clusters are actually managed by the `Event` and provided here
  * only for navigation.
  *
  * @author Garrin McGoldrick (garrin.mcgoldrick@cern.ch)
  */
class Plane {
protected:
  /** Index of this plane within the list of sensor planes in the storage */
  const size_t m_planeNum;
  /** List of hits in this plane for an event */
  std::vector<Hit*> m_hits;
  /** List of clusters in this plane for an event */
  std::vector<Cluster*> m_clusters;
  /** Map of waveforms in this plane for an event */
  std::map< std::string, std::vector<float>* > _waveforms;

  /** Only constructed by an `Event` object */
  Plane(size_t nplane);
  /** Only destructed by an `Event` object */
  ~Plane() {}

  /** Clear values so the object can be re-used */
  void clear();

public:
  /** Print hit information to standard output */
  void print();

  Hit& getHit(size_t n) const;
  Cluster& getCluster(size_t n) const;

  std::vector<float>* getWaveform(std::string waveformName) const;
  void addWaveform(std::string waveformName, std::vector<float>* wf);

  const std::vector<Hit*>& getHits() const { return m_hits; }
  const std::vector<Cluster*>& getClusters() const { return m_clusters; }

  inline size_t getPlaneNum() const { return m_planeNum; }
  inline size_t getNumHits() const { return m_hits.size(); }
  inline size_t getNumClusters() const { return m_clusters.size(); }
  inline std::map< std::string, std::vector<float>* > getWaveforms() const { return _waveforms; }


  friend class Event;
};

}

#endif // PLANE_H
