import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { APP_BASE_HREF } from '@angular/common';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { KatexModule } from 'ng-katex';

import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { FontAwesomeModule } from '@fortawesome/angular-fontawesome';
import { FormsModule } from '@angular/forms';
import { WhereIsGuidoComponent } from './Optimisation/where-is-guido/where-is-guido.component';

@NgModule({
  declarations: [
    AppComponent,
    WhereIsGuidoComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    NgbModule,
    FontAwesomeModule,
    FormsModule,
    KatexModule
  ],
  providers: [{ provide: APP_BASE_HREF, useValue: '' }], bootstrap: [AppComponent]
})
export class AppModule { }
