import { createRouter, createWebHashHistory, createWebHistory } from 'vue-router'
import CanvasView from '../views/CanvasView.vue'

const isFileProtocol = typeof window !== 'undefined' && window.location.protocol === 'file:'

const router = createRouter({
  history: isFileProtocol ? createWebHashHistory() : createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'canvas',
      component: CanvasView
    },
    {
      path: '/canvas',
      redirect: '/'
    },
    {
      path: '/canvas/:id',
      redirect: '/'
    },
    {
      path: '/:pathMatch(.*)*',
      redirect: '/'
    }
  ]
})

export default router
