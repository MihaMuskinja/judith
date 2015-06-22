#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>

#include "storage/hit.h"
#include "storage/cluster.h"
#include "storage/plane.h"

namespace Storage {

Plane::Plane(size_t nplane) : m_planeNum(nplane) {}

void Plane::clear() {
  m_hits.clear();
  m_clusters.clear();
  m_waveforms.clear();
}

void Plane::print() {
  std::cout <<
      "\nPLANE:\n"
      "  Address: " << this << "\n"
      "  Num hits: " << getNumHits() << "\n"
      "  Num clusters: " << getNumClusters() << std::endl;

  for (std::vector<Cluster*>::iterator it = m_clusters.begin();
      it != m_clusters.end(); ++it)
    (*it)->print();

  for (std::vector<Hit*>::iterator it = m_hits.begin();
      it != m_hits.end(); ++it)
    (*it)->print();
}

Hit& Plane::getHit(size_t n) const {
  if (n >= getNumHits())
    throw std::out_of_range(
        "Plane::getHit: requested hit out of range");
  return *m_hits[n];
}

Cluster& Plane::getCluster(size_t n) const {
  if (n >= getNumClusters())
    throw std::out_of_range(
        "Plane::getCluster: requated cluster out of range");
  return *m_clusters[n];
}

std::vector<float>* Plane::getWaveform(std::string waveformName) const {
  assert(!(m_waveforms.find(waveformName) == m_waveforms.end()) && 
    "Plane: requested waveform is not available");
  return m_waveforms.at(waveformName);
}

void Plane::addWaveform(std::string waveformName, std::vector<float>* wf) {
  m_waveforms.insert( std::pair< std::string, std::vector<float>* >(waveformName, wf ) );
  return;
}

}

