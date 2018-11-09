import { Component, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

import { RoomDashboardAuthenticatorComponent } from './room.dashboard.authenticator.component';

@Component({
  selector: 'app-roomdashboard',
  templateUrl: './room.dashboard.component.html'
})
export class RoomDashboardComponent extends RoomDashboardAuthenticatorComponent {

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    super(router, http, baseUrl);
  }

  protected onInit(): void {
    console.log("RoomDashboardComponent authenticated.");
  }

}
