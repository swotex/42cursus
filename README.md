# Inception of Things

### 🎯 Objective

This project is designed to deepen my knowledge in container orchestration using Kubernetes, automate deployments through CI/CD pipelines, and create reproducible environments using Vagrant.

### 🧱 Project Structure

The project is divided into several parts:

- **p1** : Setup of virtual machines with Vagrant and installation of K3s.
- **p2** : Deployment of three simple applications on the K3s cluster with ingress configuration.
- **p3** : Setup of K3d and integration of Argo CD for automatic application synchronization.
- **bonus** : Integration of GitLab as a local CI/CD solution, deployed in a dedicated namespace.

### 🛠️ Technologies Used

- K3S/K3d
- Vagrant
- Docker
- ArgoCD
- GitLab

### 🚀 Deployment Instructions

```bash
#P1
vagrant up

#P2
./start.sh

#P3
./start.sh

#bonus
./start.sh
create_repo.sh
```

### 🧑‍💻 Author

[njegat](https://https://github.com/swotex)
[tdhaussy](https://https://github.com/Rreyth)
[ltuffery](https://https://github.com/ltuffery)
