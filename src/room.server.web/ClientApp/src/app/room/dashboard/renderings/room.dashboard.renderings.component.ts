import { Component, Inject } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';

import { RoomDashboardAuthenticatorComponent } from '../room.dashboard.authenticator.component';

@Component({
  selector: 'app-roomdashboardrenderings',
  templateUrl: './room.dashboard.renderings.component.html'
})
export class RoomDashboardRenderingsComponent extends RoomDashboardAuthenticatorComponent {

  public Renderings = [];
  public ShowNoRenderingsMessage: boolean = false;

  constructor(router: Router, http: HttpClient, @Inject('BASE_URL') baseUrl: string) {
    super(router, http, baseUrl);
  }

  protected onInit(): void {
    console.log("RoomDashboardRenderingsComponent authenticated.");

    //Test data.
    this.Renderings.push({
      'id': 1,
      'name': 'hello',
      'type': 'image'
    }, {
        'id': 2,
        'name': 'world',
        'type': 'square'
    });
  }

}
